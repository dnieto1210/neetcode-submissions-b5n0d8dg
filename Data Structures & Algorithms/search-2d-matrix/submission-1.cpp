class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = row-1;
        int rr = -1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(matrix[mid][0] <= target && matrix[mid][col-1] >= target)
            {
                rr = mid;
                break;
            }
            else if(matrix[mid][0] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        if(rr == -1)
        {
            return false;
        }

        left = 0;
        right = col;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(matrix[rr][mid] == target)
            {
                return true;
            }
            else if(matrix[rr][mid] < target)
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
