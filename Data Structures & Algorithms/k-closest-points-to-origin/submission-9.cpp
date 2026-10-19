class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {


        using Node = pair<int , pair<int,int>>;
        priority_queue<Node> maxHeap;
        vector<vector<int>> result;

        for(int i = 0; i < points.size(); ++i)
        {
            int x = points[i][0];
            int y = points[i][1];

            int euc = (x * x) + (y * y);
            if(maxHeap.size() < k)
            {
                maxHeap.push({euc, {x,y}});
            }
            else
            {
                if(maxHeap.top().first > euc)
                {
                    maxHeap.pop();
                    maxHeap.push({euc, {x,y}});
                }
            }
        }

        while(!maxHeap.empty())
        {
            int x = maxHeap.top().second.first;
            int y = maxHeap.top().second.second;
            maxHeap.pop();
            result.push_back({x,y});
        }

        return result;
    }
};
