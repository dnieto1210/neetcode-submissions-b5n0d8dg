class Solution {
public:
    void backtrack(vector<int>& candidates, int idx, int sum)
    {
        if(sum == aim)
        {
            result.push_back(temp);
            return;
        }
        if(idx >= candidates.size() || sum > aim)
        {
            return;
        }

        for(int i = idx; i < candidates.size(); ++i)
        {
            int n = candidates[i];
            if(sum + n <= aim)
            {
                temp.push_back(n);
                myMap[n]--;
                
                if(myMap[n] == 0)
                {
                    //we can only move forward
                    backtrack(candidates, i+1, sum+n);
                }
                else
                {
                    //we can use it more than once
                    backtrack(candidates, i, sum+n);
                }
                myMap[n]++;
                temp.pop_back();
            }
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<int> nums;
        for(int i : candidates)
        {
            myMap[i]++;
        }

        for(auto kv : myMap)
        {
            nums.push_back(kv.first);
        }


        aim = target;
        backtrack(nums, 0,0);


        return result;
        
    }
private:
    vector<vector<int>> result;
    vector<int> temp;
    int aim;
    unordered_map<int,int> myMap;
};
