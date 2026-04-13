class Solution {
public:
    vector<bool> check;
    void backtrack(vector<vector<int>>& result, vector<int>& permutation, vector<int>& nums)
    {
        if(permutation.size() == nums.size())
        {
            result.push_back(permutation);
            return;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(check[i])
            {
                continue;
            }
            check[i] = true;
            permutation.push_back(nums[i]);
            backtrack(result, permutation, nums);
            permutation.pop_back();
            check[i]= false;
        }

        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> permutation;
        vector<vector<int>> result;
        check.resize(nums.size(), false);
        backtrack(result, permutation, nums);

        return result;
        
    }
};
