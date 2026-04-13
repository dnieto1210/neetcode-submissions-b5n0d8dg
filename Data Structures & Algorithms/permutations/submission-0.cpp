class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& perm, vector<bool>& picks)
    {
        if(perm.size() == nums.size())
        {
            result.push_back(perm);
            return;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(!picks[i])
            {
                picks[i] = true;
                perm.push_back(nums[i]);
                backtrack(nums, result, perm, picks);
                picks[i] = false;
                perm.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> perm;
        vector<bool> picks(nums.size(), false);

        backtrack(nums, result, perm, picks);
        return result;
    }
};
