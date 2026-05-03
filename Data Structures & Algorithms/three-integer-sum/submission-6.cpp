class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> result; 

        for(int i = 0; i < nums.size()-2; ++i)
        {
            int num = nums[i];
            if(i > 0 && num == nums[i-1])
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size()-1;
            while(left < right)
            {
                int target = -1 * num;
                int sum = nums[left] + nums[right];
                if(sum == target)
                {
                    result.push_back({num, nums[left], nums[right]});
                    ++left;
                    --right;
                    while(nums[left] == nums[left-1] && left < right)
                    {
                        ++left;
                    }
                    while(nums[right] == nums[right+1] && right > left)
                    {
                        --right;
                    }
                }
                else if(sum > target)
                {
                    --right;
                    while(nums[right] == nums[right+1] && right > left)
                    {
                        --right;
                    }
                }
                else
                {
                    ++left;
                    while(nums[left] == nums[left-1] && left < right)
                    {
                        ++left;
                    }
                }

            }
        }

        return result;
        
    }
};
