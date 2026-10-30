class Solution {
public:
    void dfs(int row, int col, int& area, vector<vector<int>>& grid) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return;
        }

        if(grid[row][col] == 0) {
            return;
        }

        grid[row][col] = 0;
        area = area + 1;
        maxArea = max(maxArea, area);
        dfs(row-1, col, area, grid);
        dfs(row+1, col, area, grid);
        dfs(row, col-1, area, grid);
        dfs(row, col+1, area, grid);
    }
    int DFSAll(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                int c = grid[i][j];
                if(c == 1) {
                    int temp = 0;
                    dfs(i, j, temp, grid);
                }
            }
        }

        return maxArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = DFSAll(grid);
        return result;
    }
private:
    int maxArea = 0;
};
