class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> mySet;
        int longest = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            mySet.insert(nums[i]);
            int j = 1;
            int count = 0;
            while(mySet.find(nums[i]-j) != mySet.end())
            {
                ++count;
                ++j;
            }
            int val = nums[i] - j + 1;
            int count2 = 0;
            while(mySet.find(val) != mySet.end())
            {
                ++val;
                ++count2;
            }

            int pot = max(count + 1, count2 );

            longest = max(longest, pot);
        }

        return longest;

        
    }
};
