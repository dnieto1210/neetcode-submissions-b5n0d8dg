class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0;
        int buy = prices[0];

        for(int i = 0; i < prices.size(); ++i)
        {
            if(prices[i] < buy)
            {
                buy = prices[i];
            }
            if(prices[i] > buy)
            {
                int pot = prices[i] - buy;
                maxProfit = max(maxProfit, pot);
            }
        }

        return maxProfit;
        
    }
};
