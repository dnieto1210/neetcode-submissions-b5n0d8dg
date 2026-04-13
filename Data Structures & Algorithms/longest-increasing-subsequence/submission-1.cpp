class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<vector<int>> result(nums.size()+ 1, vector<int>(nums.size()+1, 0));

        for(int i = nums.size()-1; i >= 0; --i)
        {
            for(int j = i-1; j >= 0; --j)
            {
                if(i > nums.size()-1)
                {
                    result[i][j] = 0;
                }
                else if(i < nums.size() && nums[i] <= nums[j])
                {
                    result[i][j] = result[i+1][j];
                }
                else
                {
                    result[i][j] = max(1 + result[i+1][i], result[i+1][j]);
                }

            }
        }

        int largest = INT_MIN;

        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = 0; j < nums.size(); ++j)
            {
                if(result[i][j] > largest)
                {
                    largest = result[i][j];
                }
            }
        }

        return 1 + largest;


        
    }
};
