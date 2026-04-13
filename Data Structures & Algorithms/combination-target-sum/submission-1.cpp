class Solution {
public:
    void backtrack(int idx, int r, int& target, vector<vector<int>>& result, vector<int>& combinations, vector<int>& nums)
    {
        if(r > target)
        {
            return;
        }
        if(r == target)
        {
            result.push_back(combinations);
            return;
        }

        for(int i = idx; i < nums.size(); ++i)
        {
            if(r+nums[i] <= target)
            {
                r = r+nums[i];
                combinations.push_back(nums[i]);
                backtrack(i,r, target, result, combinations, nums);
                combinations.pop_back();
                r = r - nums[i];
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> result;
        vector<int> combinations;
        backtrack(0, 0, target, result, combinations, nums);
        return result;
        
    }
};
