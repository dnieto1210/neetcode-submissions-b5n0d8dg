class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> mySet;
        for(int i : nums)
        {
            mySet.insert(i);
        }

        int longest = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            if(mySet.find(num-1) != mySet.end())
            {
                continue;
            }
            else
            {
                int check = 0;
                while(mySet.find(num) != mySet.end())
                {
                    ++check;
                    ++num;
                }
                longest = max(longest, check);

            }
        }

        return longest;

        
        
    }
};
