class Solution {
public:
    bool BS(vector<int>& row, int target)
    {
        int left = 0;
        int right = row.size()-1;

        while(left <= right)
        {
            int mid = left + (right- left) / 2;
            if(row[mid] == target)
            {
                return true;
            }
            else if(row[mid] < target)
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
            int mid = left + (right-left) / 2;

            vector<int> temp = matrix[mid];

            if(temp[0] <= target && temp[temp.size()-1] >= target)
            {
                return BS(temp, target);
            }
            else if(target > temp[temp.size()-1])
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
