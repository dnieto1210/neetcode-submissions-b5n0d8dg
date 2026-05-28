class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //1 1 2 8
        //48 24 6 1
        vector<int> pre(nums.size(), 1);
        vector<int> post(nums.size(), 1);
        vector<int> result(nums.size(), 0);

        for(int i = 1; i < nums.size(); ++i)
        {
            pre[i] = nums[i-1] * pre[i-1];
        }

        for(int i = nums.size()-2; i >= 0; --i)
        {
            post[i] = nums[i+1] * post[i+1];
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            result[i] = pre[i] * post[i];
        }
        return result;

    }
};
