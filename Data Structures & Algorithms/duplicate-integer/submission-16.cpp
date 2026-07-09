class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set<int> mySet;
        for(int i = 0; i < nums.size(); ++i)
        {
            int n = nums[i];
            if(mySet.find(n) != mySet.end())
            {
                return true;
            }
            mySet.insert(n);
        }

        return false;
        
    }
};