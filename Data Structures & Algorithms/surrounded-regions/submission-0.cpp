class Solution {
public:
    void solve(vector<vector<char>>& board) {

        using Node = pair<int,int>;
        queue<Node> q;

        for(int i =0 ; i < board.size(); ++i)
        {
            if(board[i][0] == 'O')
            {
                q.push({i,0});
                board[i][0] = 'a';
            }
            if(board[i][board[0].size()-1] == 'O')
            {
                q.push({i, board[0].size()-1});
                board[i][board[0].size()-1] = 'a';
            }
        }

        for(int i =0 ; i < board[0].size(); ++i)
        {
            if(board[0][i] == 'O')
            {
                q.push({0,i});
                board[0][i] = 'a';
            }
            if(board[board.size()-1][i] == 'O')
            {
                q.push({board.size()-1, i});
                board[board.size()-1][i] = 'a';
            }
        }

        
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;

            if(row-1 >= 0 && row-1 < board.size() && board[row-1][col] == 'O')
            {
                board[row-1][col] = 'a';
                q.push({row-1, col});
            }
            if(row+1 >= 0 && row+1 < board.size() && board[row+1][col] == 'O')
            {
                board[row+1][col] = 'a';
                q.push({row+1, col});
            }
            if(col-1 >= 0 && col-1 < board[0].size() && board[row][col-1] == 'O')
            {
                board[row][col-1] = 'a';
                q.push({row, col-1});
            }
            if(col+1 >= 0 && col+1 < board.size() && board[row][col+1] == 'O')
            {
                board[row][col+1] = 'a';
                q.push({row, col+1});
            }

        }

        //traverse the grid
        // 'a' turn back into 'O' and 'O' turn back into 'X'

        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == 'a')
                {
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }

        return;
        
    }
};
