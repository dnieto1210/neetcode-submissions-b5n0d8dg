class Solution {
public:
    int ROW;
    int COL;
    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        if(row < 0 || row >= ROW || col < 0 || col >= COL)
        {
            return 0;
        }

        if(grid[row][col] == 0)
        {
            return 0;
        }

        grid[row][col] = 0;
        int num = 1;

        num += dfs(grid, row + 1, col);
        num += dfs(grid, row-1, col);
        num += dfs(grid, row, col+1);
        num += dfs(grid, row, col-1);

        return num;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROW = grid.size();
        COL = grid[0].size();
        int maxArea = INT_MIN;

        for(int i = 0; i < ROW; ++i)
        {
            for(int j = 0; j < COL; ++j)
            {
                if(grid[i][j] == 1)
                {
                    int count = dfs(grid, i, j);
                    maxArea = max(maxArea, count);
                }
            }
        }

        return max(0, maxArea);

    }
};
