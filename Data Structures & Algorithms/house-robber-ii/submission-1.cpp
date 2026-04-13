class Solution {
public:
    int rob(vector<int>& nums) {

        //Let rob(i) denote max profit you can make without alerting the police
        //Rob(i)
        // 0 if i > n
        // max(nums[i] + Rob(i+2), Rob(i + 1)) o.w
        // nums[i] + Rob(i+2) if i = 0
        if(nums.size() == 1)
        {
            return nums[0];
        }

        vector<int> result(nums.size() + 2, 0);
        for(int i = nums.size()-2; i >= 0; --i)
        {
            int first = result[i+1];
            int second = nums[i] + result[i+2];
            result[i] = max(first, second);
        }
        

        for(int i = nums.size()-1; i >= 1; --i)
        {
            int first =result[i+1];
            int second = nums[i] + result[i+2];
            result[i] = max({first, second, result[i]});
        }

        return max(result[0], result[1]);

        
    }
};
