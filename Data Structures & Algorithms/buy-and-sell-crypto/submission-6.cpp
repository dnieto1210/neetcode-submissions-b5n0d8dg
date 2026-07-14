class Solution {
public:
    int maxProfit(vector<int>& prices) {



        int buy = prices[0];
        int maxProfit = -1;

        for(int i = 1; i < prices.size(); ++i)
        {
            int pot = prices[i];
            if(pot > buy)
            {
                maxProfit = max(maxProfit, pot-buy);
            }
            
            if(pot < buy)
            {
                buy = pot;
            }
        }

        return (maxProfit < 0) ? 0 : maxProfit;
        
    }
};
