class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set<int> mySet;
        for(int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            if(mySet.find(num) != mySet.end())
            {
                return true;
            }
            mySet.insert(num);

        }

        return false;
        
    }
};