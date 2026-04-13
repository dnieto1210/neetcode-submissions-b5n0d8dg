class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
        {
            return 1;
        }

        std::vector<std::vector<int>> dp(amount+1, std::vector<int>(coins.size()+1, 0));

        for(int i = 0; i < amount+1; ++i)
        {
            for(int j = coins.size()-1; j >= 0; --j)
            {
                
                if(i == 0)
                {
                    dp[i][j] = 1;
                }
                else if(i - coins[j] >= 0)
                {
                    int rem = i - coins[j];
                    int first = dp[rem][j];
                    int third = dp[i][j+1];
                    dp[i][j] = first + third;
                }
                else
                {
                    dp[i][j] = dp[i][j+1];
                }
            }
        }

        return dp[amount][0];

        
    }
};
