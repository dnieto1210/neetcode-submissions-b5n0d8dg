class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int longest = 0;
        unordered_set<int> mySet;
        for(int n : nums)
        {
            mySet.insert(n);
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            int length = 1;
            while(mySet.find(num - 1) != mySet.end())
            {
                num = num-1;
                ++length;
            }

            num = num + 1;
            int length2 = 0;
            while(mySet.find(num) != mySet.end())
            {
                num = num + 1;
                ++length2;
            }


            longest = max(longest, max(length,length2));

        }

        return longest;
        
    }
};
