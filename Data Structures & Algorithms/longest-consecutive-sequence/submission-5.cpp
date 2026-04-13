class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int longest = 0;
        unordered_set<int> mySet;
        for(int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            mySet.insert(num);
            while(mySet.find(num-1) != mySet.end())
            {
                --num;
            }

            int count = 0;
            while(mySet.find(num) != mySet.end())
            {
                ++count;
                ++num;
            }

            longest = max(longest, count);

        }
        return longest;
        
    }
};
