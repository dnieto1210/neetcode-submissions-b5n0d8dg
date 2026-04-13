class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> mySet;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(mySet.find(nums[i]) != mySet.end())
            {
                return true;
            }
            else
            {
                mySet.insert(nums[i]);
            }
        }

        return false;
        
    }
};