class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        std::unordered_map<int, int> myMap;

        for(int i = 0; i < nums.size(); ++i)
        {
            int rem = target - nums[i];
            if(myMap.find(rem) != myMap.end())
            {
                return {myMap[rem], i};
            }
            else
            {
                myMap[nums[i]] = i;
            }
        }

        return {};
        
    }
};
