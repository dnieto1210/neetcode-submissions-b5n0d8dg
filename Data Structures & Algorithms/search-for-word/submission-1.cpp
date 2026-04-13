class Solution {
public:
    int ROW;
    int COL;

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i)
    {
        if(i == word.length())
        {
            return true;
        }

        if(r < 0 || c < 0|| r >= ROW || c >= COL)
        {
            return false;
        }

        if(board[r][c] != word[i] || board[r][c] == '!')
        {
            return false;
        }

        char d = board[r][c];
        board[r][c] = '!';
        bool result = dfs(board, word, r-1, c, i+1) || dfs(board,word, r+1, c, i+1) || dfs(board, word, r, c-1, i+1) || dfs(board, word, r, c+1, i+1);
        board[r][c] = d;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {

        ROW = board.size();
        COL = board[0].size();

        for(int i = 0; i < ROW; ++i)
        {
            for(int j = 0; j < COL; ++j)
            {
                if(dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;

        
    }
};
