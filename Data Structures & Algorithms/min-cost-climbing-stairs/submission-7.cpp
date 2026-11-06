class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*
        Let MinCost(i) denote the minimum cost to reach the top starting at i
        MinCost(i) = 

        i == n cost[i]
        cost[i] + MinCost(i+1) or cost[i] + minCost(i+1)
        */

        vector<int> dp(cost.size() + 2, 0);
        for(int i = cost.size()-1; i >= 0; --i) {
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
        return min(dp[0], dp[1]);
    }
};
