class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i)
        {
            int n = nums[i];
            if(i != 0 && n == nums[i-1])
            {
                continue;
            }
            if(n > 0)
            {
                break;
            }

            int left = i + 1;
            int right = nums.size()-1;

            while(left < right)
            {
                int sum = n + nums[left] + nums[right];
                if(sum == 0)
                {
                    result.push_back({n, nums[left], nums[right]});
                    ++left;
                    --right;
                    while(left < right && nums[left] == nums[left-1])
                    {
                        ++left;
                    }
                    while(left < right && nums[right] == nums[right+1])
                    {
                        --right;
                    }
                }
                else if(sum < 0)
                {
                    ++left;
                    while(left < right && nums[left] == nums[left-1])
                    {
                        ++left;
                    }
                }
                else
                {
                    ///sum > 0 
                    --right;
                    while(left < right && nums[right] == nums[right+1])
                    {
                        --right;
                    }
                }
            }
        }

        return result;
        
    }
};
