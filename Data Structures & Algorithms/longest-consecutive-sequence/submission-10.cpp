class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> mySet;
        int longest = 0;
        for(int i : nums)
        {
            mySet.insert(i);
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            int n = nums[i];
            if(mySet.find(n-1) == mySet.end())
            {
                int temp = 0;
                while(mySet.find(n) != mySet.end())
                {
                    ++n;
                    ++temp;
                }

                longest = max(longest, temp);
            }
            
        }

        return longest;
        
    }
};
