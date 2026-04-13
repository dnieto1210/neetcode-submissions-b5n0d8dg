class Solution {
public:
    int findPivot(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size()-1;
        while(left < right)
        {
            int mid = left + (right-left) / 2;
            if(nums[mid] < nums[right])
            {
                right = mid;

            }
            else if(nums[mid] > nums[right])
            {
                left = mid + 1;
            }
        }

        return left;
    }

    int binarySearch(vector<int>& nums, int left, int right, int target)
    {
        int l = left;
        int r = right;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {

        int pivot = findPivot(nums);
        int left = 0;
        int right = nums.size()-1;

        if(nums[pivot] == target)
        {
            return pivot;
        }
        else if(target > nums[pivot] && nums[right] >= target)
        {
            return binarySearch(nums, pivot+ 1, right, target);
        }
        else
        {
            return binarySearch(nums, left, pivot, target);
        }
        
    }
};
