class Solution {
public:
    void backtracking(vector<int>& nums, int idx)
    {
        if(idx >= nums.size())
        {
            return;
        }

        for(int i = idx; i < nums.size(); ++i)
        {
            int n = nums[i];
            if(i > idx && n == nums[i-1])
            {
                continue;
            }
            temp.push_back(n);
            result.push_back(temp);
            backtracking(nums, i+1);
            temp.pop_back();
        }

        return;

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        result.push_back({});
        return result;


    }
private:
    vector<vector<int>> result;
    vector<int> temp;
};
