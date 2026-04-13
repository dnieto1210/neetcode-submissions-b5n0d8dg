class Solution {
public:

    bool backtrack(int row, int col, vector<vector<char>>& board, string& word, int idx)
    {
        if(idx == word.size())
        {
            return true;
        }
        if(row < 0 || row >= board.size())
        {
            return false;
        }
        if(col < 0 || col >= board[0].size())
        {
            return false;
        }
        if(board[row][col] != word[idx])
        {
            return false;
        }
        
        char save = board[row][col];
        board[row][col] = '#';
        bool up = backtrack(row-1, col, board, word, idx+1);
        bool down = backtrack(row+1, col, board, word, idx+1);
        bool left = backtrack(row, col-1, board, word, idx+1);
        bool right = backtrack(row, col+1, board, word, idx+1);
        board[row][col] = save;

        bool result = up || down || left || right;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {


        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(backtrack(i, j, board, word, 0))
                {
                    return true;
                }
            }
        }

        return false;
        
    }
};
