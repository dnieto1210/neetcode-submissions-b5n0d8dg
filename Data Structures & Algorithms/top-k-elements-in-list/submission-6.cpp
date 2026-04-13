class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using Node = pair<int,int>;
        unordered_map<int, int> myMap;
        priority_queue<Node, vector<Node>> maxHeap;

        for(int i = 0; i < nums.size(); ++i)
        {
            myMap[nums[i]]++;
        }

        for(auto kv : myMap)
        {
            maxHeap.push({kv.second, kv.first});
        }

        vector<int> result;
        while(k > 0)
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
            --k;
        }
        return result;
        
    }
};
