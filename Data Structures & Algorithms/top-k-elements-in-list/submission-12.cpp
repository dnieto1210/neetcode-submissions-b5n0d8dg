class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        using Node = pair<int, int>;
        unordered_map<int, int> myMap;
        priority_queue<Node> maxHeap;
        vector<int> result; 

        for(int n : nums)
        {
            myMap[n]++;
        }

        for(const auto kv: myMap)
        {
            maxHeap.push({kv.second, kv.first});
        }

        while(!maxHeap.empty() && k)
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
            --k;
        }
        return result;
    }
};
