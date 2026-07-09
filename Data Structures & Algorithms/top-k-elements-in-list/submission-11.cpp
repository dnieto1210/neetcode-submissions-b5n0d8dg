class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> result;
        unordered_map<int, int> myMap;
        for(int i : nums)
        {
            myMap[i]++;
        }

        using Node = pair<int, int>;
        priority_queue<Node, vector<Node>, greater<Node>> minHeap;
        for(auto kv: myMap)
        {
            if(minHeap.size() < k)
            {
                minHeap.push({kv.second, kv.first});
            }
            else
            {
                int top = minHeap.top().first;
                if(kv.second > top)
                {
                    minHeap.pop();
                    minHeap.push({kv.second, kv.first});
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
