class Solution {
public:
    void backtrack(vector<int>& nums, int idx)
    {

        if(temp.size() < nums.size())
        {
            result.push_back(temp);
        }
        else if(temp.size() == nums.size())
        {
            result.push_back(temp);
            return;
        }

        /*
        temp.push_back(nums[idx]);
        result.push_back(temp);
        */

        for(int i = idx; i < nums.size(); ++i)
        {
            temp.push_back(nums[i]);
            backtrack(nums, i+1);
            temp.pop_back();
        }

        return;

    }
    vector<vector<int>> subsets(vector<int>& nums) {

        backtrack(nums, 0);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> temp;
};
