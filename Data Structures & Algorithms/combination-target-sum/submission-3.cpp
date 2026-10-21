class Solution {
public:
    void backtrack(vector<int>& nums, int idx, int sum)
    {
        //if solution is va
        if(sum == aim)
        {
            result.push_back(temp);
            return;
        }
        if(idx >= nums.size())
        {
            return;
        }

        for(int i = idx; i < nums.size(); ++i)
        {
            if(sum + nums[i] <= aim)
            {
                temp.push_back(nums[i]);
                backtrack(nums, i, sum+ nums[i]);
                temp.pop_back();
            }
            else 
            {
                continue;
           
            }
        }

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        aim = target;
        backtrack(nums, 0, 0);
        return result;
    }
private:
    vector<int> temp;
    vector<vector<int>> result;
    int aim;
};
