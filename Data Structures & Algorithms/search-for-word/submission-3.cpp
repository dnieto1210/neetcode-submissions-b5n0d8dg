class Solution {
public:
    bool dfs(int row, int col, int idx, vector<vector<bool>>& visited, vector<vector<char>>& board, string& word)
    {
        if(idx >= word.size())
        {
            return true;
        }
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
        {
            return false;
        }
        //if we have visited this cell already return false, we cannot repeat cells
        if(visited[row][col])
        {
            return false;
        }

        //otherwise if this cell does not equal the index we want return false
        if(board[row][col] != word[idx])
        {
            return false;
        }

        //otherwise it does so mark visited and recurse
        visited[row][col] = true;
        

        //up
        bool up = dfs(row-1, col, idx+1, visited, board, word);
        //down
        bool down = dfs(row+1, col, idx+1, visited, board, word);
        //left
        bool left = dfs(row, col-1, idx+1, visited, board, word);
        //right
        bool right = dfs(row, col+1, idx+1, visited, board, word);
        
        //unmark
        visited[row][col]=  false;
        return up || down || left || right;


    }
    bool exist(vector<vector<char>>& board, string word) {


        visited.resize(board.size(), vector<bool>(board[0].size(), false));
    

        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == word[0])
                {
                    //our starting point
                    if(dfs(i, j, 0, visited, board, word))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
        
    }
private:
    vector<vector<bool>> visited;

};
