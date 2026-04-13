class Solution {
public:
    int ROW;
    int COL;

    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        if(row < 0 || col < 0 || row >= ROW || col >= COL)
        {
            return;
        }

        if(grid[row][col] == '0')
        {
            return;
        }

        grid[row][col] = '0';
        dfs(grid, row - 1, col);
        dfs(grid, row+1, col);
        dfs(grid, row, col-1);
        dfs(grid, row, col+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        ROW = grid.size();
        COL = grid[0].size();
        int islands = 0;

        for(int i = 0; i < ROW; ++i)
        {
            for(int j = 0; j < COL; ++j)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++islands;
                }


            }
        }

        return islands;

        
    }
};
