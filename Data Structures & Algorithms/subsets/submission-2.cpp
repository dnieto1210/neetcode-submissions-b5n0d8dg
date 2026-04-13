class Solution {
public:
    void backtrack(int idx, vector<int>& subsets, vector<int>&nums, vector<vector<int>>& result)
    {
        if(idx == nums.size())
        {
            return;
        }

        for(int i = idx; i < nums.size(); ++i)
        {
            subsets.push_back(nums[i]);
            result.push_back(subsets);
            backtrack(i+1, subsets, nums,result);
            subsets.pop_back();
        }
        return;

        
    }



    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subsets;
        backtrack(0, subsets, nums, result);
        result.push_back({});
        return result;
    }
};
