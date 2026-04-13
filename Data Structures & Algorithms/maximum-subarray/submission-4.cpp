class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        vector<int> dp(nums.size()+1, 0);
        int best = INT_MIN;

        for(int i = nums.size()-1; i >= 0; --i)
        {
            int num = nums[i];
            dp[i] = max(num, num + dp[i+1]);
            best = max(best, dp[i]);
        }

        return best;

    }
};
