class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> myMap;
        using Node = std::pair<int,int>;
        priority_queue<Node, vector<Node>, greater<Node>> minHeap;
        vector<int> result;

        for(int i: nums)
        {
            myMap[i]++;
        }

        for(auto kv: myMap)
        {
            int ke = kv.first;
            int v = kv.second;
            if(minHeap.size() < k)
            {
                minHeap.push({v, ke});
            }
            else
            {
                //check top
                if(minHeap.top().first < v)
                {
                    minHeap.pop();
                    minHeap.push({v,ke});
                }
                
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
