class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;

        int start = 0;

        while(start < nums.size()-2)
        {
            if(start > 0 && nums[start]==nums[start-1])
            {
                start++;
                continue;
            }
    
            int left = start + 1;
            int right = nums.size()-1;

            while(left < right)
            {
                int check = -1 * nums[start];
                int potential = nums[left] + nums[right];
                if(potential == check)
                {
                    result.push_back({nums[start], nums[left], nums[right]});
                    int j = left;
                    while(left < right && nums[left] == nums[j])
                    {
                        ++j;
                    }
                    left = j;

                }
                else if(potential > check)
                {
                    --right;
                }
                else if(potential < check)
                {
                    ++left;
                }


            }
            start++;
        }
        
        return result;
    }
};
