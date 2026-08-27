class Solution {
public:
    bool BS(vector<int>& matrix, int target)
    {
        int left = 0;
        int right = matrix.size()-1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(matrix[mid] == target)
            {
                return true;
            }
            else if(matrix[mid] < target)
            {
                left = mid + 1;
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
            int mid = left + (right-left) / 2;
            if(matrix[mid][0] <= target && matrix[mid][matrix[0].size()-1] >= target)
            {
                return BS(matrix[mid], target);
            }
            else if(target < matrix[mid][0])
            {
                right = mid-1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return false;
    }
};
