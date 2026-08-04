class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {


        using Node = pair<int,int>;
        int row = grid.size();
        int col = grid[0].size();
        queue<Node> myQueue;

        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(grid[i][j] == 2)
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
                if(grid[i][j-1] == 1)
                {
                    grid[i][j-1] = 1 + grid[i][j];
                    myQueue.push({i, j-1});

                }
            }

            //right
            if(j+1 < col)
            {
                if(grid[i][j+1] == 1)
                {
                    grid[i][j+1] = 1 + grid[i][j];
                    myQueue.push({i, j+1});
                }
            }

            //up
            if(i-1 >= 0)
            {
                if(grid[i-1][j] == 1)
                {
                    grid[i-1][j] = 1 + grid[i][j];
                    myQueue.push({i-1, j});
                }
            }

            //down
            if(i+1 < row)
            {
                if(grid[i+1][j] == 1)
                {
                    grid[i+1][j]= 1 + grid[i][j];
                    myQueue.push({i+1, j});
                }
            }
        }

        int max = 0;
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                int curr = grid[i][j];
                if(curr == 1)
                {
                    return -1;
                }
                if(curr > max)
                {
                    max = curr;
                }
            }
        }

        if(max == 0)
        {
            return 0;
        }
        return max-2;

        
    }
};
