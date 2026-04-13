class Solution {
public:
    int maxProfit(vector<int>& prices) {

        std::vector<std::vector<int>> dp(3, std::vector<int>(prices.size()+1, 0));

        for(int j = prices.size()-1; j >= 0; --j)
        {
            for(int i = 0; i < 3; ++i)
            {
                int future = (i+1) % 3;
                if(j >= prices.size())
                {
                    dp[i][j] = 0;
                }
                else if(i == 0)
                {
                    dp[i][j] = max(-1 * prices[j]+ dp[future][j+1], dp[i][j+1]);
                }
                else if(i == 1)
                {
                    dp[i][j] = max(prices[j] + dp[future][j+1], dp[i][j+1]);

                }
                else if(i == 2)
                {
                    dp[i][j] = dp[future][j+1];
                }

            }
        }

        /*
        for(int i = 0; i < 3; ++i)
        {
            for(int j = prices.size()-1; j >= 0; --j)
            {
                int future = (i+1) % 3;
                if(j >= prices.size())
                {
                    dp[i][j] = 0;
                }
                else if(i == 0)
                {
                    dp[i][j] = max(-1 * prices[j]+ dp[future][j+1], dp[i][j+1]);
                }
                else if(j == 1)
                {
                    dp[i][j] = max(prices[j] + dp[future][j+1], dp[i][j+1]);

                }
                else if(j == 2)
                {
                    dp[i][j] = dp[future][i+1];
                }

            }
        }
        */


        return dp[0][0];
        
    }
};
