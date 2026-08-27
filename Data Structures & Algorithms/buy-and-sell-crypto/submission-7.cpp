class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy = INT_MAX;
        int profit = 0;


        for(int i = 0; i < prices.size(); ++i)
        {
            int curr = prices[i];
            if(curr < buy)
            {
                buy = curr;
            }
            else if(curr-buy > profit)
            {
                profit = curr-buy;
            }
        }

        return profit;
    }
};
