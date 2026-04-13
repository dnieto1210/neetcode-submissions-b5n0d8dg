class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, int target, int sum, int index)
    {
        if(sum > target || index >= nums.size())
        {
            return;
        }
        if(sum == target)
        {
            result.push_back(temp);
            return;
        }

        //take some option again
        temp.push_back(nums[index]);
        backtrack(nums, result, temp, target, sum+nums[index], index);
        temp.pop_back();

        //skip that option
        backtrack(nums, result, temp, target, sum, index+1);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int sum = 0;
        int index = 0;
        vector<int> temp;
        backtrack(nums, result, temp, target, sum, index);
        return result;

        
    }
};
