class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());


        for(int i = 0; i < nums.size(); ++i)
        {
            int first = nums[i];

            if(i != 0 && nums[i] == nums[i-1])
            {
                continue;
            }


            int left = i + 1;
            int right = nums.size()-1;

            while(left < right)
            {
                int target = -1 * first;
                int sum = nums[left] + nums[right];
                if(sum + first == 0)
                {
                    result.push_back({first, nums[left], nums[right]});
                    --right;
                    while(nums[right] == nums[right+1])
                    {
                        --right;
                    }
                }
                else if(sum + first < 0)
                {
                    ++left;
                    while(nums[left] == nums[left-1])
                    {
                        ++left;
                    }
                }
                else
                {
                    --right;
                    while(nums[right] == nums[right+1])
                    {
                        --right;
                    }
                }
            }

        }


        return result;
        
    }
};
