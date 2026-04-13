class Solution {
public:
    void backtrack(int idx, int sum, int& target, vector<vector<int>>& result, vector<int>& combinations, vector<int>& candidates)
    {
        
        if(sum == target)
        {
            result.push_back(combinations);
            return;
        }
        if(idx >= candidates.size() || sum > target)
        {
            return;
        }

        for(int i = idx; i < candidates.size(); ++i)
        {
            if(i > idx && candidates[i] == candidates[i-1])
            {
                continue;
            }
            if(sum + candidates[i] <= target)
            {
                combinations.push_back(candidates[i]);
                sum += candidates[i];
                backtrack(i + 1, sum, target, result, combinations, candidates);
                combinations.pop_back();
                sum -= candidates[i];
            }
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combinations;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        backtrack(0, 0, target, result, combinations, candidates);
        return result;
        
    }
};
