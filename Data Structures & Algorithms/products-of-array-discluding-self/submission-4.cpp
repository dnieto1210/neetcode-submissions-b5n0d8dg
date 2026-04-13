class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //prefix and postfix sums

        std::vector<int> pre(nums.size(), 1);
        std::vector<int> pos(nums.size(), 1);
        std::vector<int> result(nums.size(), 0);

        for(int i = 1; i < nums.size(); ++i)
        {
            pre[i] = nums[i-1] * pre[i-1];
        }

        for(int i = nums.size()-2; i >= 0; --i)
        {
            pos[i] = nums[i+1] * pos[i+1];
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            result[i] = pre[i] * pos[i];
        }
        return result;

    }
};
