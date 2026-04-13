class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int inf = 100000;
        int n = coins.size();
        vector<vector<int>> result(amount+2, vector<int>(n+1, inf));

        for(int i = 0; i <= amount; ++i)
        {
            for(int j = n-1; j >= 0; --j)
            {
                int cost = coins[j];
                if(i == 0)
                {
                    result[i][j] = 0;
                }
                else if(cost > i)
                {
                    continue;
                }
                else
                {
                    result[i][j] = result[i][j+1];
                    if((i-cost) >= 0)
                    {
                        int first = result[i-cost][j];
                        int second = result[i-cost][j+1];
                        int third = 1 + min(first,second);
                        result[i][j] = min(result[i][j], third);
                    }
                    
                }
            }

             
        }

        return (result[amount][0] == inf) ? -1 : result[amount][0];

        
        
    }
};
