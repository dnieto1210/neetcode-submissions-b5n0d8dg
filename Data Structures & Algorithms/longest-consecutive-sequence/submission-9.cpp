class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int longest = 0;
        unordered_set<int> mySet;
        for(int i : nums)
        {
            mySet.insert(i);
        }

        for(int i : nums)
        {
            if(mySet.find(i-1) != mySet.end())
            {
                continue;
            }
            else
            {
                int curr = 1;
                int num = i+1;
                while(mySet.find(num) != mySet.end())
                {
                    num++;
                    curr++;
                }
                longest = max(longest, curr);
            }
        }

        return longest;
        
    }
};
