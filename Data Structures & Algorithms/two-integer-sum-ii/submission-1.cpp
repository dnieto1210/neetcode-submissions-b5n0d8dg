class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size()-1;

        while(start < end)
        {
            int check = numbers[start] + numbers[end];
            if(check == target)
            {
                return {start+1, end+1};
            }
            else if(check < target)
            {
                start++;
            }
            else if(check > target)
            {
                end--;
            }
        }

        return {};
        
    }
};
