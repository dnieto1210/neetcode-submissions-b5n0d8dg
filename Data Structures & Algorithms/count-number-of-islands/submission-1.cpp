class Solution {
public:

    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
        {
            return;
        }
        if(grid[row][col] == '*')
        {
            //we already marked it
            return;
        }
        if(grid[row][col] == '0')
        {
            //we dont care about water
            return;
        }

        //otherwise it is a 1
        //right, left, up, down
        grid[row][col] = '*';
        dfs(grid, row-1, col);
        dfs(grid, row+1, col);
        dfs(grid, row, col+1);
        dfs(grid, row, col-1);
        return;

    }
    int numIslands(vector<vector<char>>& grid) {
        int count_islands = 0;

        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++count_islands;
                }

            }
        }
        return count_islands;
    }
};
