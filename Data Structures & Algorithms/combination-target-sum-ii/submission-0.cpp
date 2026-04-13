class Solution {
public:
    void backtrack(vector<int>& arr, set<vector<int>>& result, vector<int>& sub, int target, int sum, int index)
    {
        if(sum == target)
        {
            result.insert(sub);
            return;
        }
        if(sum > target || index >= arr.size())
        {
            return;
        }


        sub.push_back(arr[index]);
        backtrack(arr, result, sub, target, sum+arr[index], index+1);
        sub.pop_back();

        backtrack(arr, result, sub, target, sum, index+1);
    

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sub;
        int sum = 0;
        int index = 0;
        set<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, result, sub, target, sum, index);

        vector<vector<int>> mine;
        for(auto v: result)
        {
            mine.push_back(v);
        }
        

        return mine;
        
    }
};
