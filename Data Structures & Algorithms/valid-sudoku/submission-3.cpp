class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // (row / 3) * 3 + (col / 3)

        std::unordered_map<int, std::unordered_map<char, int>> row, col, box;

        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                char c = board[i][j];
                if(c == '.')
                {
                    continue;
                }

                if(row[i].find(c) != row[i].end())
                {
                    return false;
                }
                else
                {
                    row[i][c] = 1;
                }

                if(col[j].find(c) != col[j].end())
                {
                    return false;
                }
                else
                {
                    col[j][c] = 1;
                }

                int box_idx = (i/3)*3 + (j/3);
                if(box[box_idx].find(c) != box[box_idx].end())
                {
                    return false;
                }
                else
                {
                    box[box_idx][c] = 1;
                }
            }
        }

        return true;
        
    }
};
