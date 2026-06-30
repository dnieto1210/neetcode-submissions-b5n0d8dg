class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        int maxSub = INT_MIN;
        for(int i = 0; i < nums.size(); ++i)
        {
            int n = nums[i];
            sum += n;
            maxSub = max(maxSub, sum);

            if(sum < 0)
            {
                sum = 0;
            }
        }

        return maxSub;

    }
};
