class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            int match = nums[i];
            for(int j = (i + 1); j < nums.size(); j++)
            {
                if(nums[j] == match)
                {
                    return true;
                }
            }
        }
        return false;

    }
};
