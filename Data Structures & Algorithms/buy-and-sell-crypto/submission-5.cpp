class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy = prices[0];
        int profit = INT_MIN;

        for(int i = 1; i < prices.size(); ++i)
        {
            int p = prices[i];
            if(p > buy)
            {
                profit = max(profit, p-buy);
            }
            else
            {
                //p <= buy
                buy = p;
            }
        }
        
        return (profit >= 0) ? profit : 0;
    }
};
