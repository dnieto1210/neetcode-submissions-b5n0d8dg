class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        using Node = pair<int,int>;
        queue<Node> myQ;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2) {
                    myQ.push({i,j});
                }
            }
        }

        while(!myQ.empty()) {
            auto tp = myQ.front();
            myQ.pop();
            int r = tp.first;
            int c = tp.second;

            if(r-1 >= 0 && grid[r-1][c] == 1){
                grid[r-1][c] = grid[r][c] + 1;
                myQ.push({r-1, c});
            }
            if(r+1 < grid.size() && grid[r+1][c] == 1){
                grid[r+1][c] = grid[r][c] + 1;
                myQ.push({r+1, c});
            }
            if(c-1 >= 0 && grid[r][c-1] == 1){
                grid[r][c-1] = grid[r][c] + 1;
                myQ.push({r, c-1});
            }
            if(c+1 < grid[0].size() && grid[r][c+1] == 1){
                grid[r][c+1] = grid[r][c] + 1;
                myQ.push({r, c+1});
            }
        }

        int maxMin = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    return -1;
                }

                maxMin = max(maxMin, grid[i][j]);
            }
        }

        if(maxMin == 0) {
            return 0;
        }

        return maxMin - 2;
        
    }
};
