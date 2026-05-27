class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        using Node = pair<int,int>;
        unordered_map<int,int> myMap;
        priority_queue<Node, vector<Node>, greater<Node>> minHeap;
        for(int i = 0; i < nums.size(); ++i)
        {
            myMap[nums[i]]++;
        }
        for(auto kv : myMap)
        {
            if(minHeap.size() < k)
            {
                minHeap.push({kv.second, kv.first});
            }
            else
            {
                //minHeap size is k
                if(minHeap.top().first < kv.second)
                {
                    minHeap.pop();
                    minHeap.push({kv.second, kv.first});
                }
            }

        }
        vector<int> result;
        while(!minHeap.empty())
        {
            auto temp = minHeap.top();
            minHeap.pop();
            result.push_back(temp.second);
        }
        
        return result;
    }
};
