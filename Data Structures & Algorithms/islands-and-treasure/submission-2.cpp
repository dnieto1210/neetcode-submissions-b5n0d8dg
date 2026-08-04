class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        using Node = pair<int,int>;
        queue<Node> myQueue;
        int INF = 2147483647;

        //get all the locations of the treasure chest
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(grid[i][j] == 0)
                {
                    myQueue.push({i, j});
                }
            }
        }

        while(!myQueue.empty())
        {
            Node curr = myQueue.front();
            myQueue.pop();
            int i = curr.first;
            int j = curr.second;

            //left
            if(j-1 >= 0)
            {
                if(grid[i][j-1] == INF)
                {
                    grid[i][j-1] = grid[i][j] + 1;
                    myQueue.push({i, j-1});
                }
            }
            
            //right
            if(j+1 < col)
            {
                if(grid[i][j+1] == INF)
                {
                    grid[i][j+1] = grid[i][j] + 1;
                    myQueue.push({i, j+1});
                }
            }

            //up
            if(i-1 >= 0)
            {
                if(grid[i-1][j] == INF)
                {
                    grid[i-1][j] = grid[i][j] + 1;
                    myQueue.push({i-1, j});
                }
            }

            //down
            if(i+1 < row)
            {
                if(grid[i+1][j] == INF)
                {
                    grid[i+1][j] = grid[i][j] + 1;
                    myQueue.push({i+1, j});
                }
            }

        }

        return;
        
    }
};
