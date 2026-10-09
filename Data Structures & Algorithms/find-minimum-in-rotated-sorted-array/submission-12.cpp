class Solution {
public:
    int findMin(vector<int> &nums) {

        int left = 0;
        int right = nums.size()-1;
        int res = INT_MAX;
        while(left <= right)
        {
            int mid = left + (right-left)/2;

            if(nums[mid] <= nums[right])
            {
                res = min(nums[mid], res);
                right = mid-1;
            }
            else
            {
                //nums[mid] > nums[right]
                res = min(nums[mid], res);
                left = mid + 1;
            }

        }

        return res;
        
    }
};
