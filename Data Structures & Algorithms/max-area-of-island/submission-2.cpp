class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        int R = grid.size();
        int C = grid[0].size();
        if(row < 0 || row >= R || col < 0 || col >= C || grid[row][col] == 0)
        {
            return 0;
        }

        grid[row][col] = 0;

        int down = dfs(grid, row+1, col);
        int up = dfs(grid, row-1, col);
        int left = dfs(grid, row, col - 1);
        int right = dfs(grid, row, col+1);

        return 1 + down + up + left + right;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        maxArea = 0;

        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                int check = grid[i][j];
                if(check == 1)
                {
                    int pot = dfs(grid, i, j);
                    maxArea = max(maxArea, pot);
                }
            }
        }

        return maxArea;

    
        
    }
private:
    int maxArea;
};
