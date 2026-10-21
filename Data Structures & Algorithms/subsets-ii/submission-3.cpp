class Solution {
public:
    void backtrack(vector<int>& nums, int idx)
    {
        if(idx == nums.size())
        {
            result.push_back(temp);
            return;
        }
        else if(idx < nums.size())
        {
            result.push_back(temp);
        }

        for(int i = idx; i < nums.size(); ++i)
        {
            int n = nums[i];
            if(i > idx && nums[i] == nums[i-1])
            {
                continue;
            }

            temp.push_back(n);
            backtrack(nums, i+1);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        backtrack(nums, 0);        
        return result;
    }
private:
    vector<int> temp;
    vector<vector<int>> result;

};
