class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //assume nums1 is smaller
        if(nums2.size() > nums1.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int total = nums1.size() + nums2.size(); //total elements
        int half = total / 2; //rounds down
        int left = 0;
        int right = nums1.size();

        while(left <= right)
        {
            int middle = (left+right)/2; //how many elements will we gets from nums1 array
            int rem = half - middle; //remaining number of elements that nums2 will get

            int nums1Left = (middle == 0) ? INT_MIN : nums1[middle-1];
            int nums1Right = (middle == nums1.size()) ? INT_MAX : nums1[middle];
            int nums2Left = (rem == 0) ? INT_MIN : nums2[rem-1];
            int nums2Right = (rem == nums2.size()) ? INT_MAX : nums2[rem];

            if(nums1Left <= nums2Right && nums2Left <= nums1Right)
            {
                if(total % 2 == 0)
                {
                    return (std::max(nums1Left, nums2Left) + std::min(nums1Right, nums2Right)) / 2.0;
                }
                else
                {
                    return std::min(nums1Right, nums2Right);
                }

            }
            else if(nums1Left > nums2Right)
            {
                right = middle-1;

            }
            else
            {
                left = middle + 1;

            }
        }

        //we should never reach here

        return -1;

        
        
    }
};
