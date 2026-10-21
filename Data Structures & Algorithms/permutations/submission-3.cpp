class Solution {
public:

    void backtrack(vector<int>& nums, int idx)
    {
        if(temp.size() == nums.size())
        {
            result.push_back(temp);
            return;
        }

        for(int i = idx; i < nums.size(); ++i)
        {
            int n = nums[i];
            if(mySet.find(n) != mySet.end())
            {
                continue;
            }
            //otherwise
            temp.push_back(n);
            mySet.insert(n);
            backtrack(nums, idx);
            mySet.erase(n);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
private:
    unordered_set<int> mySet;
    vector<vector<int>> result;
    vector<int> temp;
};
