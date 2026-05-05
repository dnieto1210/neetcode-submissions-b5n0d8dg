class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int max_profit = 0;
        int buy = INT_MAX;

        for(int i = 0;i < prices.size(); ++i)
        {
            int num = prices[i];
            if(num < buy)
            {
                buy = num;
            }
            else
            {
                if(num - buy > max_profit)
                {
                    max_profit = num-buy;
                }
            }

        }

        return max_profit;
        
    }
};
