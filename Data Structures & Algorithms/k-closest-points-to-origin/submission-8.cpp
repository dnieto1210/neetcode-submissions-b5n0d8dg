class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        using Node = pair<double, pair<int,int>>;
        priority_queue<Node> maxHeap;

        for(int i = 0; i < points.size(); ++i)
        {
            int x = points[i][0];
            int y = points[i][1];

            int x_s = x * x;
            int y_s = y * y;
            int sum = x_s + y_s;
            double dist = std::sqrt(sum);
            if(i >= k)
            {
                if(dist < maxHeap.top().first)
                {
                    maxHeap.pop();
                    maxHeap.push({dist, {x,y}});
                }

            }
            else
            {
                maxHeap.push({dist, {x,y}});
            }
        }

        vector<vector<int>> result;
        while(!maxHeap.empty())
        {
            auto curr = maxHeap.top();
            maxHeap.pop();
            auto p = curr.second;

            result.push_back({p.first, p.second});
        }

        return result;
        
    }
};
