class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using Node = pair<int,int>;
        priority_queue<Node, vector<Node>, greater<Node>> minHeap;
        unordered_map<int,int> myMap;
        for(int i = 0; i < nums.size(); ++i)
        {
            myMap[nums[i]]++;
        }
        for(auto kv: myMap)
        {
            if(minHeap.size() < k)
            {
                minHeap.push({kv.second, kv.first});
            }
            else
            {
                if(kv.second > minHeap.top().first)
                {
                    minHeap.pop();
                    minHeap.push({kv.second, kv.first});
                }
            }
        }

        vector<int> result;
        while(!minHeap.empty())
        {
            int num = minHeap.top().second;
            minHeap.pop();
            result.push_back(num);
        }

        return result;
        
    }
};
