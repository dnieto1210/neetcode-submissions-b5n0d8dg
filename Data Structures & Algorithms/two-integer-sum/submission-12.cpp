class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> myMap;
        for(int i = 0; i < nums.size(); ++i)
        {
            int n = nums[i];
            int rem = target - n;
            if(myMap.find(rem) != myMap.end())
            {
                return {myMap[rem], i};
            }
            myMap[n] = i;
        }

        return {};
        
    }
};
