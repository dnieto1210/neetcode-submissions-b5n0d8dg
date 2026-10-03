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
                int streak = 0;
                int curr = n;
                while(mySet.find(curr) != mySet.end())
                {
                    streak++;
                    curr = curr + 1;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
        
    }
};
