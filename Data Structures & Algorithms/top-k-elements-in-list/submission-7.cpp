class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using Node = std::pair<int,int>;
        std::priority_queue<Node, std::vector<Node>> myHeap;
        std::unordered_map<int, int> myMap;

        for(int i = 0; i < nums.size(); ++i)
        {
            myMap[nums[i]]++;
        }

        for(auto kv: myMap)
        {
            myHeap.push({kv.second, kv.first});
        }

        std::vector<int> result;

        while(k > 0 && !myHeap.empty())
        {
            auto pair = myHeap.top();
            myHeap.pop();
            result.push_back(pair.second);
            --k;
        }

        return result;
        
    }
};
