class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int check = nums[0];

        for(int i = 1; i < nums.size(); ++i)
        {
            check = check ^ nums[i];
        }

        return check;
        
    }
};
