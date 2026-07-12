class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size()-1;

        while(left < right)
        {
            int pot = numbers[left] + numbers[right];
            if(pot == target)
            {
                return {left+1, right+1};
            }
            else if(pot < target)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return {};
        
    }
};
