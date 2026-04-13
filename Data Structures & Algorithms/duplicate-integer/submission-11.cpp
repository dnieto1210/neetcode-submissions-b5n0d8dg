class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(mySet.find(nums[i]) != mySet.end())
            {
                return true;
            }
            mySet.insert(nums[i]);
        }

        return false;
        
    }
};