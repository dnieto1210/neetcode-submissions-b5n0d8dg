class Solution {
public:
    bool normalBS(vector<int>& arr, int target)
    {
        int left = 0;
        int right = arr.size()-1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(arr[mid] == target)
            {
                return true;
            }
            else if(arr[mid] < target)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int left = 0;
        int right = matrix.size()-1;

        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(matrix[mid][0] <= target && matrix[mid][matrix[0].size()-1] >= target)
            {
                return normalBS(matrix[mid], target);
            }
            else if(matrix[mid][0] > target)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }

        return false;
        
    }
};
