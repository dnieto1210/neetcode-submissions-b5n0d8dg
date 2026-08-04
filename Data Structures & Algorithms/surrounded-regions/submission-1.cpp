class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited)
    {
        int R = board.size();
        int C = board[0].size();
        if(visited[row][col] == false)
        {
            visited[row][col] = true;
            board[row][col] = 'A';

            //left
            if(col - 1 >= 0)
            {
                if(board[row][col-1] == 'O')
                {
                    dfs(row, col-1, board, visited);
                }
            }

            //right
            if(col + 1 < C)
            {
                if(board[row][col+1] == 'O')
                {
                    dfs(row, col + 1, board, visited);
                }

            }

            //up
            if(row-1 >= 0)
            {
                if(board[row-1][col] == 'O')
                {
                    dfs(row-1, col, board, visited);
                }
            }

            //down
            if(row+1 < R)
            {
                if(board[row+1][col] == 'O')
                {
                    dfs(row+1, col, board, visited);
                }

            }


        }

        return;
    }
    void DFSAll(vector<pair<int,int>>& nodes, vector<vector<char>>& board, vector<vector<bool>>& visited)
    {
        for(int i = 0; i < nodes.size(); ++i)
        {
            int x = nodes[i].first;
            int y = nodes[i].second;
            if(visited[x][y] == false)
            {
                dfs(x, y, board, visited);
            }
        }

        return;

    }
    void solve(vector<vector<char>>& board) {

        int R = board.size();
        int C = board[0].size();

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        vector<pair<int,int>> nodes;

        for(int i = 0; i < C; ++i)
        {
            if(board[0][i] == 'O')
            {
                nodes.push_back({0, i});
            }
            if(board[R-1][i] == 'O')
            {
                nodes.push_back({R-1, i});
            }
        }

        for(int i = 0; i < R; ++i)
        {
            if(board[i][0] == 'O')
            {
                nodes.push_back({i, 0});
            }

            if(board[i][C-1] == 'O')
            {
                nodes.push_back({i, C-1});
            }
        }

        DFSAll(nodes, board, visited);

        for(int i = 0; i < R; ++i)
        {
            for(int j = 0; j < C; ++j)
            {
                if(board[i][j] == 'A')
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
