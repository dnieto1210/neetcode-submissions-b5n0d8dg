class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> result(nums.size(), 1);

        for(int i = 1; i < nums.size(); ++i)
        {
            result[i] = result[i-1] * nums[i-1];
        }

        //we currently have the prefix in our array

        int mult = 1;
        for(int i = nums.size()-1; i >= 0; --i)
        {
            result[i] = mult * result[i];
            mult = mult * nums[i];
        }

        return result;

    }
};
