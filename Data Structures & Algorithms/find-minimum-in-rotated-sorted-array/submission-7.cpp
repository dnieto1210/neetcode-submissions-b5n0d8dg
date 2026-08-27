class Solution {
public:
    int findMin(vector<int> &nums) {

        int lowest = INT_MAX;

        int left = 0;
        int right = nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right -left)/2;

            if(nums[mid] <= nums[right] && nums[mid] >= nums[left])
            {
                lowest = min(lowest, nums[mid]);
                right = mid-1;
            }
            else if(nums[left] >= nums[mid] && nums[mid] <= nums[right])
            {
                lowest = min(lowest, nums[mid]);
                right = mid-1;
            }
            else if(nums[mid] >= nums[left] && nums[mid] >= nums[right])
            {
                lowest = min(lowest, nums[mid]);
                left = mid+1;
            }
        }

        return lowest;
        
    }
};
