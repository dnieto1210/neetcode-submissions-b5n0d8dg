class Solution {
public:
    void backtrack(vector<int>& nums, int idx)
    {
        if(idx == nums.size())
        {
            return;
        }

        for(int i = idx; i < nums.size(); ++i)
        {
            int num = nums[i];
            temp.push_back(num);
            result.push_back(temp);
            backtrack(nums, i + 1);
            temp.pop_back();

        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        
        backtrack(nums, 0);
        result.push_back({});
        return result;

        
        
    }
private:
    vector<vector<int>> result;
    vector<int> temp;
};
