class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        vector<int> dp1(nums.size()+2, 0);
        vector<int> dp2(nums.size()+2, 0);
        for(int i = nums.size()-2; i >= 0; --i) {
            dp1[i] = max(nums[i]+ dp1[i+2], dp1[i+1]);
        }
        for(int i = nums.size()-1; i >= 1; --i) {
            dp2[i] = max(nums[i] + dp2[i+2], dp2[i+1]);
        }
        int maxMoney = 0;
        for(int i = 0; i < dp1.size(); ++i) {
            maxMoney = max({maxMoney, dp1[i], dp2[i]});
        }
        return maxMoney;
    }
};
