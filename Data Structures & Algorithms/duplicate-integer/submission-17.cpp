class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set<int> mySet;
        for(int n : nums)
        {
            if(mySet.find(n) != mySet.end())
            {
                return true;
            }
            mySet.insert(n);
        }

        return false;
        
    }
};