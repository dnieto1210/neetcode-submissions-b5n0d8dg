class Solution {
public:
    void backtracking(vector<int>& nums, int target, int idx)
    {
        if(target == 0)
        {
            result.push_back(temp);
            return;
        }

        if(target < 0)
        {
            return;
        }

        for(int i = idx; i < nums.size(); ++i)
        {
            int n = nums[i];
            temp.push_back(n);
            backtracking(nums, target - n, i);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        backtracking(nums, target, 0);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> temp;

};
