class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = INT_MIN;
        int buy = prices[0];
        
        for(int i = 1; i < prices.size(); ++i)
        {
            int sell = prices[i]- buy;
            if(sell > profit)
            {
                profit = sell;
            }

            if(prices[i] < buy)
            {
                buy = prices[i];
            }

            
        }

        if(profit < 0)
        {
            return 0;
        }

        return profit;


        
    }
};
