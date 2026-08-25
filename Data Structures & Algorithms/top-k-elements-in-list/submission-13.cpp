class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using Node = pair<int,int>;

        unordered_map<int, int> myMap;
        priority_queue<Node, vector<Node>, greater<>> minHeap;
        vector<int> result;

        for(int n : nums)
        {
            myMap[n]++;
        }

        for(const auto kv: myMap)
        {
            int n = kv.first;
            int freq = kv.second;

            if(minHeap.size() < k)
            {
                minHeap.push({freq, n});
            }
            else
            {
                if(minHeap.top().first < freq)
                {
                    minHeap.pop();
                    minHeap.push({freq,n});
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
