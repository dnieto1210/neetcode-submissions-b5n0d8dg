class Solution {
public:

    int ROW;
    int COL;
    int INF;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int BFS(vector<vector<int>>& grid, int r, int c)
    {
        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        using Node = pair<int, int>;
        queue<Node> myQueue;
        visited[r][c] = true;
        myQueue.push({r, c});
        int steps = 0;

        while(!myQueue.empty())
        {
            int qs = myQueue.size();
            while(qs--)
            {
                auto p = myQueue.front();
            myQueue.pop();

            if(grid[p.first][p.second] == 0)
            {
                return steps;
            }

            for(int i = 0; i < directions.size(); ++i)
            {
                int new_row = p.first + directions[i][0];
                int new_col = p.second + directions[i][1];
                if(new_row < 0 || new_row >= ROW || new_col < 0 || new_col >= COL)
                {
                    continue;
                }
                if(visited[new_row][new_col] == true || grid[new_row][new_col] == -1)
                {
                    continue;
                }
                else
                {
                    myQueue.push({new_row, new_col});
                    visited[new_row][new_col] = true;
                }
            }
            }
            ++steps;

        }

        return steps;
    }


    void islandsAndTreasure(vector<vector<int>>& grid) {
        ROW = grid.size();
        COL = grid[0].size();
        INF = 2147483647;

        for(int i = 0; i < ROW; ++i)
        {
            for(int j = 0; j < COL; ++j)
            {
                if(grid[i][j] == INF)
                {
                    int result = BFS(grid, i, j);
                    if(result != 0)
                    {
                        grid[i][j] = result;
                    }

                }
            }
        }

        return;
        
    }
};
