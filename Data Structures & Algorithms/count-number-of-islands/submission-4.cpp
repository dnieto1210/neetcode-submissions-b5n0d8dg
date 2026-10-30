class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return;
        }
        if(grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';
        dfs(row-1, col, grid);
        dfs(row+1, col, grid);
        dfs(row, col-1, grid);
        dfs(row,col+1, grid);
        return;
    }
    int DFSAll(vector<vector<char>>& grid) {
        //if a cell is 1 it is unviisted
        int count = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                char c = grid[i][j];
                if(c == '1') {
                    ++count;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
    int numIslands(vector<vector<char>>& grid) {
        int result = DFSAll(grid);
        return result;
    }
};
