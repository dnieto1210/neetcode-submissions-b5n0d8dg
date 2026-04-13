class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> mySet;
        for(int i : nums)
        {
            mySet.insert(i);
        }

        int length = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(mySet.find(nums[i] - 1) == mySet.end())
            {
                int check = nums[i] + 1;
                int temp_l = 1;
                while(mySet.find(check) != mySet.end())
                {
                    check++;
                    temp_l++;

                }

                length = std::max(length, temp_l);

            }
        }

        return length;


        
    }
};
