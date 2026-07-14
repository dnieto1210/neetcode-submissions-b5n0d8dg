class Solution {
public:
    bool binarySearch(vector<int>& arr, int target)
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
                left = mid + 1;
            }
            else
            {
                right = mid- 1;
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
            vector<int> check = matrix[mid];
            int start = 0;
            int end = check.size()-1;

            if(check[start] <= target && check[end] >= target)
            {
                return binarySearch(check, target);
            }
            else if(check[start] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }


        return false;
        
    }
};
