class Solution {
public:

    void backtrack(int idx, vector<int>& subsets, vector<vector<int>>& result, vector<int>& nums)
    {
        if(idx == nums.size())
        {
            return;
        }

        for(int i = idx; i < nums.size(); ++i)
        {
            if(i > idx && nums[i] == nums[i-1])
            {
                continue;
            }

            subsets.push_back(nums[i]);
            result.push_back(subsets);
            backtrack(i + 1, subsets, result, nums);
            subsets.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subsets;
        vector<vector<int>> result;
        backtrack(0, subsets, result, nums);
        result.push_back({});

        return result;
        
    }
};
