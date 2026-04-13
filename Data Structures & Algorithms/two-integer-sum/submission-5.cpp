class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::unordered_map<int,int> myMap;

        for(int i = 0; i < nums.size(); ++i)
        {
            int curr = nums[i];
            int rest = target - curr;
            if(myMap.find(rest) != myMap.end())
            {
                return {myMap[rest], i};
            }
            myMap[curr] = i;
        }
        
        return {};
    }
};
