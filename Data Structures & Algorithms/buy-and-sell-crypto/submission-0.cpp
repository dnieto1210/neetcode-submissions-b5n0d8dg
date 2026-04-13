class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int sell = 0;
        int profit = 0;

        for(int i = 0; i < prices.size(); ++i)
        {
            if(prices[i] < buy)
            {
                buy = prices[i];
            }
            else if(prices[i] > buy)
            {
                sell = prices[i];
                profit = std::max(profit, sell - buy);
            }
        }

        return profit;


        
    }
};
