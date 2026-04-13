class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> possible;

        for(int i = 0; i < nums.size(); i++)
        {
            if(possible.find(target - nums[i]) == possible.end())
            {
                possible[nums[i]] = i;
            }
            else
            {
                return {possible[target - nums[i]], i};
            }
        }

        return {};

        
    }
};
