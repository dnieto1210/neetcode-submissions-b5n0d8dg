class Solution {
public:
    set<vector<int>> mySet;

    void backtrack(vector<int>& nums, vector<int> subset, int idx)
    {
        if(subset.size() <= nums.size())
        {
            mySet.insert(subset);
        }
        if(idx >= nums.size())
        {
            return;
        }

        subset.push_back(nums[idx]);
        backtrack(nums, subset, idx+1);
        subset.pop_back();
        backtrack(nums, subset, idx+1);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtrack(nums, subset, 0);


        for(auto v: mySet)
        {
            result.push_back(v);
        }

        return result;





        
    }
};
