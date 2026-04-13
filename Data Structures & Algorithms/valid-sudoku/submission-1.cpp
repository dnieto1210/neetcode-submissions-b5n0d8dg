class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, set<int>> rows;
        unordered_map<int,set<int>> cols;
        unordered_map<int, set<int>> boxes;

        int r = board.size();
        int c = board[0].size();

        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {

                //check if invalid
                if(board[i][j] == '.')
                {
                    continue;
                }
                //check row
                if(rows[i].find(board[i][j]) != rows[i].end())
                {
                    return false;
                }
                else
                {
                    rows[i].insert(board[i][j]);
                }

                //check cols

                if(cols[j].find(board[i][j]) != cols[j].end())
                {
                    return false;
                }
                else
                {
                    cols[j].insert(board[i][j]);
                }


                //check boxes
                int r_i = (i / 3) * 3;
                int c_i = (j / 3);
                int idx = r_i + c_i;
                if(boxes[idx].find(board[i][j]) != boxes[idx].end())
                {
                    return false;
                }
                else
                {
                    boxes[idx].insert(board[i][j]);
                }



            }
        }

        return true;
        
    }
};
