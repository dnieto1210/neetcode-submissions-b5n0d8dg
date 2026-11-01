class Solution {
public:
    void dfs(int row, int col, int prev, vector<vector<bool>>& visited, vector<vector<int>>& heights) {
        if(row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size()) {
            return;
        }
        if(visited[row][col] == true) {
            return;
        }
        if(prev > heights[row][col]) {
            return;
        }

        visited[row][col] = true;
        dfs(row-1, col, heights[row][col], visited, heights);
        dfs(row+1, col, heights[row][col], visited, heights);
        dfs(row, col-1, heights[row][col], visited, heights);
        dfs(row, col+1, heights[row][col], visited, heights);
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {


        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));

        
        for(int i = 0; i < heights[0].size(); ++i) {
            dfs(0, i, heights[0][i], pacific, heights);
            dfs(heights.size()-1, i, heights[heights.size()-1][i], atlantic, heights);
        }
        for(int i = 0; i < heights.size(); ++i) {
            dfs(i, 0, heights[i][0], pacific, heights);
            dfs(heights.size()-1-i, heights[0].size()-1, heights[heights.size()-1-i][heights[0].size()-1], atlantic, heights);
        }

        vector<vector<int>> result;
        for(int i = 0; i < heights.size(); ++i) {
            for(int j = 0; j < heights[0].size(); ++j) {
                if(atlantic[i][j] == true && pacific[i][j] == true) {
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};
