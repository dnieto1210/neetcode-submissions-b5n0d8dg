class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        unordered_set<int> row_bounds;
        unordered_set<int> col_bounds;
        int ele = matrix[0].size() * matrix.size();
        vector<int> result;
        bool right = true;
        bool down = false;
        bool left = false;
        bool up = false;
        int row = 0;
        int col = 0;
        row_bounds.insert(matrix.size());
        col_bounds.insert(matrix[0].size());

        for(int i = 0; i < ele; ++i)
        {
            if(right)
            {
                result.push_back(matrix[row][col]);
                if(col + 1 >= matrix[0].size() || col_bounds.find(col+1) != col_bounds.end())
                {
                    right = false;
                    down = true;
                    row_bounds.insert(row);
                    //col_bounds.insert(col);
                    ++row;
                }
                else
                {
                    //keep going right
                    ++col;
                }
            }
            else if(down)
            {
                result.push_back(matrix[row][col]);
                if(row + 1 >= matrix.size() || row_bounds.find(row+1) != row_bounds.end())
                {
                    down = false;
                    left = true;
                    col_bounds.insert(col);
                    //row_bounds.insert(row);
                    --col;
                }
                else
                {
                    //keep going down
                    ++row;
                }

            }
            else if(left)
            {
                result.push_back(matrix[row][col]);
                if(col-1 < 0 || col_bounds.find(col-1) != col_bounds.end())
                {
                    left = false;
                    up = true;
                    row_bounds.insert(row);
                    //col_bounds.insert(col);
                    --row;
                }
                else
                {
                    //keep going left 
                    --col;
                }

            }
            else if(up)
            {
                result.push_back(matrix[row][col]);
                if(row-1 < 0 || row_bounds.find(row-1) != row_bounds.end())
                {
                    up = false;
                    right = true;
                    col_bounds.insert(col);
                    ++col;
                }
                else
                {
                    //keep going up
                    --row;
                }

            }

        }
        return result;
    }
};
