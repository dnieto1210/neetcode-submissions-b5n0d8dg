class Solution {
public:

    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        int R = grid.size();
        int C = grid[0].size();
        if(row < 0 || row >= R || col < 0 || col >= C || grid[row][col] == '0')
        {
            return;
        }

        //mark as visited 
        grid[row][col] = '0';

        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
        dfs(grid, row, col+1);
        dfs(grid, row, col-1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {

        int count = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j =0; j < grid[0].size(); ++j)
            {
                char check = grid[i][j];
                if(check == '1')
                {
                    count += 1;
                    dfs(grid, i, j);

                }
            }
        }

        return count;

        
    }
};
