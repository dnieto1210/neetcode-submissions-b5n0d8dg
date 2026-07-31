class Solution {
public:
    void backtracking(vector<int>& candidates, int target, int idx)
    {
        if(target == 0)
        {
            mySet.insert(temp);
            return;
        }

        if(target < 0)
        {
            return;
        }

        for(int i = idx; i < candidates.size(); ++i)
        {
            int n = candidates[i];
            if(i > idx && n == candidates[i-1])
            {
                continue;
            }
            temp.push_back(n);
            backtracking(candidates, target- n, i+1);
            temp.pop_back();
        }
        return;

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        backtracking(candidates, target, 0);
        for(auto v : mySet)
        {
            result.push_back(v);
        }
        return result;
        
    }
private:
    vector<vector<int>> result;
    vector<int> temp;
    set<vector<int>> mySet;

};
