class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n+2, 0);

        for(int i = n; i >= 0; --i)
        {
            if(i == n)
            {
                dp[i] = 1;
            }
            else if(i > n)
            {
                dp[i]= 0;
            }
            else
            {
                dp[i] = dp[i+1] + dp[i+2];
            }
        }

        return dp[0];
        
    }
};
