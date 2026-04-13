class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {


        int total = 0;
        for(int &n : nums)
        {
            total += n;
        }
        if (target > total || target < -total) return 0;

        std::vector<std::vector<int>> dp(2*total + 1, std::vector<int>(nums.size()+1, 0));
        int offset = total;
        dp[offset][nums.size()]= 1;
        for(int j = nums.size()-1; j >=0; --j)
        {
            for(int i = 0; i < 2*total+1; ++i)
            {
                int ways = 0;
                if(nums[j] + i < 2*total+1)
                {
                    ways += dp[i+nums[j]][j+1];
                }
                if(i - nums[j] >= 0)
                {
                    ways += dp[i-nums[j]][j+1];
                }

                dp[i][j] = ways;
            

            }
        }


        return dp[total+target][0]; 
    }
};
