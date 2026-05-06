class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int size_row = matrix[0].size();
        int left = 0;
        int right = matrix.size()-1;

        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(matrix[mid][0] <= target && matrix[mid][size_row-1] >= target)
            {
                //search this array
                int arr_left = 0;
                int arr_right = size_row-1;
                while(arr_left <= arr_right)
                {
                    int arr_mid = arr_left + (arr_right - arr_left) / 2;
                    if(matrix[mid][arr_mid] == target)
                    {
                        return true;
                    }
                    else if(matrix[mid][arr_mid] > target)
                    {
                        arr_right = arr_mid-1;
                    }
                    else
                    {
                        arr_left = arr_mid+1;
                    }
                }
                return false;


            }
            else if(target > matrix[mid][size_row-1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return false;
        
    }
};
