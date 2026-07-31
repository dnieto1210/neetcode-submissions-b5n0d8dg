class Solution {
public:

    void backtracking(vector<int>& nums)
    {
        if(temp.size() == size)
        {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            int n = nums[i];
            if(used[i] == true)
            {
                continue;
            }
            used[i] = true;
            temp.push_back(n);
            backtracking(nums);
            used[i] = false;
            temp.pop_back();
        }

        return;


    }
    vector<vector<int>> permute(vector<int>& nums) {
        size = nums.size();
        used.resize(size, false);
        backtracking(nums);

        return result;
        
    }
private:
    vector<vector<int>> result;
    vector<int> temp;
    int size;
    vector<bool> used;

};
