class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> myMap;
        std::vector<int> result;
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>> myHeap;

        for(int& i : nums)
        {
            myMap[i]++;
        }

        for(auto& pair : myMap)
        {
            myHeap.push({pair.second, pair.first});
        }

        int j = 0;
        while(j < k)
        {
            std::pair<int,int> p = myHeap.top();
            result.push_back(p.second);
            myHeap.pop();
            j++;
        }

        return result;


        
    }
};
