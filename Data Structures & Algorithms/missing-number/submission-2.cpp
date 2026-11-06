class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int sum = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            res = res + nums[i];
            sum = sum + i;
        }
        sum = sum + nums.size();
        return sum - res;
        
    }
};
