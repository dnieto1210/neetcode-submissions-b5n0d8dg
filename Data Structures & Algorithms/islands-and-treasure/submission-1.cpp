class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {

        //find all cells that have treasure chest
        using Node = std::pair<int,int>;
        std::queue<Node> myQueue;
        int INF = INT_MAX;

        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 0)
                {
                    myQueue.push({i, j});

                }
            }
        }


        //start multisource bfs

        //i dont need a visited data strcutre because we know if cell is not -1 0 or INF then it has been visited

        while(!myQueue.empty())
        {
            auto curr = myQueue.front();
            myQueue.pop();
            int row = curr.first;
            int col = curr.second;

            // check up, down, left, or right and add them to the queue
            if(row-1 >= 0 && row-1 < grid.size())
            {
                if(grid[row-1][col] == INF)
                {
                    grid[row-1][col] = grid[row][col] + 1;
                    myQueue.push({row-1, col});


                }
            }
            
            if(row+1 >= 0 && row+1 < grid.size())
            {
                if(grid[row+1][col] == INF)
                {
                    grid[row+1][col] = grid[row][col] + 1;
                    myQueue.push({row+1, col});

                }
            }

            if(col-1 >= 0 && col-1 < grid[0].size())
            {
                if(grid[row][col-1] == INF)
                {
                    grid[row][col-1] = grid[row][col] + 1;
                    myQueue.push({row, col-1});
                }
            }
            if(col+1 >= 0 && col+1 < grid[0].size())
            {
                if(grid[row][col+1] == INF)
                {
                    grid[row][col+1] = grid[row][col] + 1;
                    myQueue.push({row, col+1});
                }
            }
        }

        return;
        
    }
};
