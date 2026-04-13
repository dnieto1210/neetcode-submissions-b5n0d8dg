class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(const int& i : nums)
        {
            total += i;
        }

        if(total % 2 == 1)
        {
            return false; //odd total is not posisble 
        }

        int half = total / 2;

        std::vector<std::vector<bool>> dp(half+1, vector<bool>(nums.size()+1, false));

        for(int j = 0; j < (half+1); ++j)
        {
            for(int i = nums.size()-1; i >= 0; --i)
            {
                if(j < 0)
                {
                    dp[j][i] = false;
                }
                else if(j == 0)
                {
                    dp[j][i] = true;
                }
                else
                {
                    dp[j][i] = (j-nums[i] >= 0) ? max(dp[j-nums[i]][i+1], dp[j][i+1]) : dp[j][i+1];
                }
            }
        }

        return dp[half][0];
        
    }
};
