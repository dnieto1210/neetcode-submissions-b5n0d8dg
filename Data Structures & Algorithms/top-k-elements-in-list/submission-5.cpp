class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using Node = std::pair<int, int>;

        std::priority_queue<Node, vector<Node>> maxHeap;
        std::unordered_map<int,int> myMap;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(myMap.find(nums[i]) != myMap.end())
            {
                myMap[nums[i]]++;
            }
            else
            {
                myMap[nums[i]] = 1;
            }

        }

        for(auto kv : myMap)
        {
            Node curr = {kv.second, kv.first};
            maxHeap.push(curr);
        }

        vector<int> result;

        while(k > 0)
        {
            Node temp = maxHeap.top();
            maxHeap.pop();
            result.push_back(temp.second);
            --k;

        }  

        return result;
        
    }
};
