class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        using Node = pair<int,int>;
        stack<Node> myStack;
        myStack.push({i,j});

        while(!myStack.empty())
        {
            auto kv = myStack.top();
            myStack.pop();
            if(visited[kv.first][kv.second] == false)
            {
                visited[kv.first][kv.second] = true;
                //add the edges to the list
                
                //up
                if(kv.first-1 >= 0 && grid[kv.first-1][kv.second] == '1')
                {
                    myStack.push({kv.first-1, kv.second});
                }

                //down
                if(kv.first + 1 < grid.size() && grid[kv.first+1][kv.second] == '1')
                {
                    myStack.push({kv.first+ 1, kv.second});
                }

                //left
                if(kv.second-1 >= 0 && grid[kv.first][kv.second-1] == '1')
                {
                    myStack.push({kv.first, kv.second-1});
                }

                //right
                if(kv.second+1 < grid[0].size() && grid[kv.first][kv.second + 1] == '1')
                {
                    myStack.push({kv.first, kv.second+1});
                }
            }
        }

        return;

    }
    int WFSAll(vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        //we already marked each node as unvisited
        int count = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1' && visited[i][j] == false)
                {
                    dfs(grid, visited, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
    int numIslands(vector<vector<char>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int result =  WFSAll(grid, visited);
        return result;
        
    }
};
