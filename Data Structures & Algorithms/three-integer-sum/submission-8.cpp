class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {


        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i)
        {
            if(i != 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            if(nums[i] > 0)
            {
                break;
            }

            int left = i + 1;
            int right = nums.size()-1;
            int n = nums[i];

            while(left < right)
            {
                int sum = nums[left] + nums[right];
                int total = sum + n;
                if(total == 0)
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
                else if(total > 0)
                {
                    --right;
                    while(left < right && nums[right] == nums[right+1])
                    {
                        --right;
                    }
                }
                else if(total < 0)
                {
                    ++left;
                    while(left < right && nums[left] == nums[left-1])
                    {
                        ++left;
                    }
                }


            }

        }

        return result;
        
    }
};
