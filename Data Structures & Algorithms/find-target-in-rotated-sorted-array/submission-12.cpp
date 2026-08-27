class Solution {
public:
    int BS(vector<int>& nums, int left, int right, int target)
    {
        while(left <= right)
        {
            int mid = left + (right-left) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                left = mid+1;
            }
            else
            {
                //nums[mid] > target
                right = mid-1;
            }

        }


        return -1;

    }

    int findMin(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size()-1;
        int lowest = INT_MAX;
        int idx = -1;
        while(left <= right)
        {
            int mid = left + (right -left)/2;
            if(nums[mid] <= nums[right])
            {
                if(nums[mid] < lowest)
                {
                    lowest = nums[mid];
                    idx = mid;
                }
                right = mid-1;
            }
            else
            {
                //nums[mid] > nums[right]
                if(nums[mid] < lowest)
                {
                    lowest = nums[mid];
                    idx = mid;
                }
                left = mid + 1;
            }

        }

        return idx;
    }
    int search(vector<int>& nums, int target) {

        int lowestIdx = findMin(nums);
        if(target >= nums[lowestIdx] && target <= nums[nums.size()-1])
        {
            return BS(nums, lowestIdx, nums.size()-1, target);
        }
        else
        {
            return BS(nums, 0, lowestIdx-1, target);
        }
        
    }
};
