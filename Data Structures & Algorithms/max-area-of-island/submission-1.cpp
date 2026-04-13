class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0)
        {
            return 0;
        }

        //otherwise we have a 1 

        grid[row][col] = 0;
        int up = dfs(grid, row -1, col);
        int down = dfs(grid, row+1, col);
        int left = dfs(grid, row, col-1);
        int right = dfs(grid , row, col+1);
        int total = up + down + left + right;

        return 1 + total;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxArea = 0;

        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    int num = dfs(grid, i, j);
                    maxArea = std::max(maxArea, num);
                }
            }
        }

        return maxArea;
        
    }
};
