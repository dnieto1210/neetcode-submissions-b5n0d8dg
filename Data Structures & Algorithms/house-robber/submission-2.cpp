class Solution {
public:
    int rob(vector<int>& nums) {
        /*
        Let MaxRob(i) denote the max money i can make if I rob from the ith house to the end.
        MaxRob(i) = cost[i] + MaxRob(i+2)
        i > n return 0 
        */
        vector<int> dp(nums.size()+2, 0);
        for(int i = nums.size()-1; i >= 0; --i) {
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }
        int maxMoney = INT_MIN;
        for(int i = 0; i < dp.size(); ++i){
            maxMoney = max(maxMoney, dp[i]);
        }
        return maxMoney;
        
    }
};
