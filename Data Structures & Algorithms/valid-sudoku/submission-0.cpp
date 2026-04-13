class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> row;
        std::unordered_map<int, std::unordered_set<char>> col;
        std::unordered_map<int, std::unordered_set<char>> sq;

        for(int r = 0; r < 9; ++r)
        {
            for(int c = 0; c < 9; ++c)
            {
                if(board[r][c] == '.')
                {
                    continue;
                }
                if(row[r].find(board[r][c]) != row[r].end())
                {
                    return false;
                }
                else
                {
                    row[r].insert(board[r][c]);
                }

                if(col[c].find(board[r][c]) != col[c].end())
                {
                    return false;
                }
                else
                {
                    col[c].insert(board[r][c]);
                }

                int sq_r = r / 3;
                int sq_c = c / 3;
                int sq_key = sq_r * 3 + sq_c;
                if(sq[sq_key].find(board[r][c]) != sq[sq_key].end())
                {
                    return false;
                }
                else
                {
                    sq[sq_key].insert(board[r][c]);
                }
            }
        }

        return true;

        
    }
};
