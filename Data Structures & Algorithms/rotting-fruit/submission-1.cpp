class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        using Node = std::pair<int,int>;
        std::queue<Node> myQueue;

        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 2)
                {
                    myQueue.push({i, j});
                }
            }
        }


        
        while(!myQueue.empty())
        {
            auto curr = myQueue.front();
            myQueue.pop();
            int row = curr.first;
            int col = curr.second;

            //check left, up, down, right

            if(row-1 >= 0 && row-1 < grid.size())
            {
                if(grid[row-1][col] == 1)
                {
                    grid[row-1][col] = grid[row][col] + 1;
                    myQueue.push({row-1, col});
                }
            }

            if(row+1 >= 0 && row+1 < grid.size())
            {
                if(grid[row+1][col] == 1)
                {
                    grid[row+1][col] = grid[row][col] + 1;
                    myQueue.push({row+1, col});
                }
            }
            if(col-1 >= 0 && col < grid[0].size())
            {
                if(grid[row][col-1] == 1)
                {
                    grid[row][col-1] = grid[row][col] + 1;
                    myQueue.push({row, col-1});
                }
            }
            if(col+1 >= 0 && col+1 < grid[0].size())
            {
                if(grid[row][col+1] == 1)
                {
                    grid[row][col+1] = grid[row][col] + 1;
                    myQueue.push({row, col+1});
                }
            }
        }

        //traverse thru grid again and see if there is any 1s
        int max_num = 0;

        for(int i =0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
                
                if(grid[i][j] > max_num)
                {
                    max_num = grid[i][j];
                }
            }
        }

        return (max_num == 0 ) ? max_num : max_num- 2;
        
    }
};
