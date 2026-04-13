class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {


        vector<vector<bool>> pacific (heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic (heights.size(), vector<bool>(heights[0].size(), false));

        using Node = pair<int,int>;
        queue<Node> p;
        queue<Node> a;

        for(int i = 0; i < heights.size(); ++i)
        {
            p.push({i, 0});
            a.push({i, heights[0].size()-1});
        }

        for(int i = 0; i < heights[0].size(); ++i)
        {
            p.push({0, i});
            a.push({heights.size()-1, i});
        }

        //bfs for pacific
        while(!p.empty())
        {
            auto curr = p.front();
            p.pop();
            int row = curr.first;
            int col = curr.second;
            pacific[row][col] = true;

            if(row-1 >= 0 && row-1 < heights.size())
            {
                if(heights[row-1][col] >= heights[row][col] && pacific[row-1][col] == false)
                {
                    p.push({row-1, col});
                }
            }
            if(row+1 >= 0 && row+1 < heights.size())
            {
                if(heights[row+1][col] >= heights[row][col] && pacific[row+1][col] == false)
                {
                    p.push({row+1, col});
                }
            }
            if(col-1 >= 0 && col-1 < heights[0].size())
            {
                if(heights[row][col-1] >= heights[row][col] && pacific[row][col-1] == false)
                {
                    p.push({row, col-1});
                }
            }
            if(col+1 >= 0 && col+1 < heights[0].size())
            {
                if(heights[row][col+1] >= heights[row][col] && pacific[row][col+1] == false)
                {
                    p.push({row, col+1});
                }
            }
        }

        //bfs for atlantic
        while(!a.empty())
        {
            auto curr = a.front();
            a.pop();
            int row = curr.first;
            int col = curr.second;
            atlantic[row][col] = true;

            if(row-1 >= 0 && row-1 < heights.size())
            {
                if(heights[row-1][col] >= heights[row][col] && atlantic[row-1][col] == false)
                {
                    a.push({row-1, col});
                }
            }
            if(row+1 >= 0 && row+1 < heights.size())
            {
                if(heights[row+1][col] >= heights[row][col] && atlantic[row+1][col] == false)
                {
                    a.push({row+1, col});
                }
            }
            if(col-1 >= 0 && col-1 < heights[0].size())
            {
                if(heights[row][col-1] >= heights[row][col] && atlantic[row][col-1] == false)
                {
                    a.push({row, col-1});
                }
            }
            if(col+1 >= 0 && col+1 < heights[0].size())
            {
                if(heights[row][col+1] >= heights[row][col] && atlantic[row][col+1] == false)
                {
                    a.push({row, col+1});
                }
            }
        }

        //traverse the 2d vector bools and add the points that are true in both pacific and atlantic
        vector<vector<int>> result;

        for(int i = 0; i < heights.size(); ++i)
        {
            for(int j = 0; j < heights[0].size(); ++j)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    result.push_back({i,j});
                }
            }
        }

        return result;
        
    }
};
