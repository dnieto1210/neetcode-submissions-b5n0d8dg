class Solution {
public:
    int maxProduct(vector<int>& nums) {

        vector<int> maxSub(nums.size(), 0);
        vector<int> minSub(nums.size(), 0);

        maxSub[nums.size()-1] = nums[nums.size()-1];
        minSub[nums.size()-1] = nums[nums.size()-1];

        for(int i = nums.size()-2; i >= 0; --i)
        {
            int n = nums[i];

            if(n > 0)
            {
                maxSub[i] = max(n * maxSub[i+1], n);
                minSub[i] = min(n * minSub[i+1], n);
            }
            else if(n < 0)
            {
                maxSub[i] = max(n * minSub[i+1], n);
                minSub[i] = min(n * maxSub[i+1], n);
            }
            
        }
        
        int result = INT_MIN;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(maxSub[i] > result)
            {
                result = maxSub[i];
            }
        }
        return result;
    }
};
