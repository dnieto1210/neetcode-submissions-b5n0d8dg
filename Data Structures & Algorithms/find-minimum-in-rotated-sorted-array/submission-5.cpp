class Solution {
public:
    int findMin(vector<int> &nums) {

        int left = 0;
        int right = nums.size()-1;
        int mini = INT_MAX;

        while(left <= right)
        {
            int mid = left + (right - left ) / 2;
            if(nums[mid] <= nums[right] && nums[mid] >= nums[left])
            {
                right =mid -1 ;
                mini = min(mini, nums[mid]);
            }
            else if(nums[mid] <= nums[left] && nums[mid] <= nums[right])
            {
                right = mid - 1;
                mini = min(mini,nums[mid]);
            }
            else if(nums[mid] >= nums[left] && nums[mid] >= nums[right])
            {
                left = mid + 1;
                mini = min(mini, nums[mid]);
            }

        }

        return mini;
        
    }
};
