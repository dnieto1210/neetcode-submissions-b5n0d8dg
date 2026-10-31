class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        using Node = pair<int,int>;
        queue<Node> myQ;

        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 0) {
                    myQ.push({i,j});
                }
            }
        }

        while(!myQ.empty()) {
            auto tp = myQ.front();
            myQ.pop();
            int r = tp.first;
            int c = tp.second;

            if(r - 1 >= 0 && grid[r-1][c] == INT_MAX) {
                grid[r-1][c] = grid[r][c] + 1;
                myQ.push({r-1, c});
            }
            if(r+1 < grid.size() && grid[r+1][c] == INT_MAX) {
                grid[r+1][c] = grid[r][c] + 1;
                myQ.push({r+1, c});
            }
            if(c-1 >= 0 && grid[r][c-1] == INT_MAX) {
                grid[r][c-1] = grid[r][c] + 1;
                myQ.push({r, c-1});
            }
            if(c+1 < grid[0].size() && grid[r][c+1] == INT_MAX) {
                grid[r][c+1] = grid[r][c] + 1;
                myQ.push({r, c+1});
            }
        }

        return;
        
    }
};
