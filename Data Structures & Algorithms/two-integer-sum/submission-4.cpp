class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>myMap;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            int leftover = target - nums[i];

            if(myMap.find(leftover) != myMap.end())
            {
                return {myMap[leftover], i};
            }
            myMap[nums[i]] = i;
        }

        return {};
        
    }
};
