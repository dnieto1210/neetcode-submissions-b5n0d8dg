class Solution {
public:

    void backtrack(int index, vector<int>& subset, vector<vector<int>>& result, vector<int>& nums)
    {
        int n = nums.size();
        if(index > n)
        {
            return;
        }

        for(int i = index; i < n; ++i)
        {
            subset.push_back(nums[i]);
            result.push_back(subset);
            backtrack(i+1, subset, result, nums);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subsets;
        backtrack(0, subsets,result, nums);
        result.push_back({});
        return result;
        
    }
};
