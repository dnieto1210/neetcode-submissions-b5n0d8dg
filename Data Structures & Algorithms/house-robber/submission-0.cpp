class Solution {
public:
    int rob(vector<int>& nums) {

        vector<int> result(nums.size()+2, 0);
        for(int i = nums.size()-1; i >= 0; --i)
        {
            int first = nums[i] + result[i+2];
            int second = result[i + 1];
            result[i] = max(first, second);
        }

        return result[0];
        
    }
};
