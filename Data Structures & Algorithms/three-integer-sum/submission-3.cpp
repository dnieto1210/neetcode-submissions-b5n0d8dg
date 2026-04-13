class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort the array
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i = 0; i < nums.size()-2; ++i)
        {
            int left = i + 1;
            int right = nums.size()-1;
            int target = nums[i];

            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            while(left < right)
            {
                int sum = nums[right] + nums[left];
                if(sum == (-1 * target))
                {
                    result.push_back({target, nums[right], nums[left]});
                    ++left;
                    while(nums[left-1] == nums[left])
                    {
                        ++left;
                    }
                    --right;
                    while((right+1) < nums.size() && nums[right+1] == nums[right])
                    {
                        --right;
                    }
                }
                else if(sum < (-1 * target))
                {
                    ++left;
                    while(nums[left-1] == nums[left])
                    {
                        ++left;
                    }
                }
                else
                {
                    --right;
                    while((right+1) < nums.size() && nums[right+1] == nums[right])
                    {
                        --right;
                    }
                }
            }


        }
        return result;
        
    }
};
