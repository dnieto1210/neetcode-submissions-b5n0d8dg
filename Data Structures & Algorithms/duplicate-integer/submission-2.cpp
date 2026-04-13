class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> les;
        for(int i = 0; i < nums.size(); i++)
        {
            if (les.find(nums[i]) != les.end())
            {
                return true;
            }
            les.insert(nums[i]);
        }
        return false;

    }
};
