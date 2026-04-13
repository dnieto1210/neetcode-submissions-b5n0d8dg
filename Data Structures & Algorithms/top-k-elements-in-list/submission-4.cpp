class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using Node = std::pair<int,int>;
        std::vector<int> result;
        std::unordered_map<int,int> myMap;
        std::priority_queue<Node, vector<Node>, std::greater<Node>> minHeap;


        for(int n: nums)
        {
            myMap[n] += 1;
        }

        for(auto kv: myMap)
        {
            minHeap.push({kv.second, kv.first});
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        while(!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
        
    }
};
