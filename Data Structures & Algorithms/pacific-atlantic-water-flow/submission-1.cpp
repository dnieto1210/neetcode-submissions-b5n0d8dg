class Solution {
public:

    void dfs(int row, int col, bool p, vector<vector<int>>& grid)
    {
        int R = grid.size();
        int C = grid[0].size();
        if(p)
        {
            //check whether visited
            if(pacific[row][col] == false)
            {
                pacific[row][col] = true;

                //for each valid neighbor dfs
                
                //left
                if(col - 1 >= 0)
                {
                    if(grid[row][col-1] >= grid[row][col])
                    {
                        dfs(row, col-1, p, grid);
                    }
                }

                if(col+1 < C)
                {
                    if(grid[row][col+1] >= grid[row][col])
                    {
                        dfs(row, col+1, p, grid);
                    }
                }

                if(row+1 < R)
                {
                    if(grid[row+1][col] >= grid[row][col])
                    {
                        dfs(row+1, col, p, grid);
                    }
                }

                if(row - 1 >= 0)
                {
                    if(grid[row-1][col] >= grid[row][col])
                    {
                        dfs(row-1, col, p, grid);
                    }
                }


            }

        }
        else
        {
            if(atlantic[row][col] == false)
            {
                atlantic[row][col] = true;

                //for each valid neighbor dfs
                
                //left
                if(col - 1 >= 0)
                {
                    if(grid[row][col-1] >= grid[row][col])
                    {
                        dfs(row, col-1, p,grid);
                    }
                }

                if(col+1 < C)
                {
                    if(grid[row][col+1] >= grid[row][col])
                    {
                        dfs(row, col+1, p, grid);
                    }
                }

                if(row+1 < R)
                {
                    if(grid[row+1][col] >= grid[row][col])
                    {
                        dfs(row+1, col, p, grid);
                    }
                }

                if(row - 1 >= 0)
                {
                    if(grid[row-1][col] >= grid[row][col])
                    {
                        dfs(row-1, col, p, grid);
                    }
                }


            }

        }
    }

    void DFSAll(vector<pair<int,int>>& nodes, bool p, vector<vector<int>>& grid)
    {
        for(int i = 0; i < nodes.size(); ++i)
        {
            pair<int,int> coord = nodes[i];
            int x = coord.first;
            int y = coord.second;
            if(p)
            {
                if(pacific[x][y] == false)
                {
                    //not yet visited
                    dfs(x,y, p,grid);
                }
                
            }
            else
            {
                //we are atlantic
                if(atlantic[x][y] == false)
                {
                    dfs(x,y, p, grid);
                }
            }
        }

        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int R = heights.size();
        int C = heights[0].size();

        pacific.resize(R, vector<bool>(C, false));
        atlantic.resize(R, vector<bool>(C, false));


        vector<pair<int,int>> atlanticNodes;
        vector<pair<int,int>> pacificNodes;

        for(int i = 0; i < C; ++i)
        {
            pacificNodes.push_back({0, i});
            atlanticNodes.push_back({R-1, i});
        }

        for(int i = 0; i < R; ++i)
        {
            pacificNodes.push_back({i, 0});
            atlanticNodes.push_back({i, C-1});
        }

        DFSAll(pacificNodes, true, heights);
        DFSAll(atlanticNodes, false, heights);

        for(int i = 0; i < R; ++i)
        {
            for(int j = 0; j < C; ++j)
            {
                if(pacific[i][j] == true && atlantic[i][j] == true)
                {
                    vector temp = {i, j};
                    result.push_back(temp);
                }
            }
        }

        return result;

        
    }
private:
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    vector<vector<int>> result;

};
