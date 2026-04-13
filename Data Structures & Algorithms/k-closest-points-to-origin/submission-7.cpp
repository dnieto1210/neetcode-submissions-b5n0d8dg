class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        std::priority_queue<std::pair<double,int>> maxHeap;
        std::vector<std::vector<int>> result;

        for(int i = 0; i < points.size(); ++i)
        {
            const std::vector<int>& rep = points[i];
            int x = rep[0];
            int y = rep[1];

            int mult = (x * x) + (y * y);
            double res = sqrt(mult);

            if(maxHeap.size() < k)
            {
                maxHeap.push({res,i});
            }
            else if(maxHeap.size() == k)
            {
                auto  top = maxHeap.top();
                if(res < top.first)
                {
                    maxHeap.pop();
                    maxHeap.push({res, i});
                }
            }

        }

        while(!maxHeap.empty())
        {
            auto temp = points[maxHeap.top().second];
            result.push_back({temp[0], temp[1]});
            maxHeap.pop();
        }

        return result;
        
    }
};
