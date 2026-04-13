class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }

        std::unordered_set<int> mySet;

        for(int i = 0; i < nums.size(); ++i)
        {
            mySet.insert(nums[i]);
        }

        int longest = 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            int count = 1;
            int curr = nums[i];
            while(mySet.find(curr - 1) != mySet.end())
            {
                ++count;
                --curr;
            }
            longest = std::max(count, longest);

        }

        return longest;
        
    }
};
