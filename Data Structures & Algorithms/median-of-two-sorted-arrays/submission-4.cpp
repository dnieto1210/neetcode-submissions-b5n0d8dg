class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int totalSize = nums1.size() + nums2.size();
        int half = totalSize / 2;
        //we want to partition into 2 halfs
        //if we have an even then partition two halves which are equal on each side
        //if we have odd then partion the even amount in the first half and the odd amount on the second half
        int left = 0;
        int right = nums1.size();

        while(left <= right)
        {
            int mid = left + (right-left) / 2; //the amount of elements to take from array nums1
            int rem = half- mid; //the amount of elements to take from array nums2
            int n1Left = (mid <= 0) ? INT_MIN : nums1[mid-1];
            int n1Right = (mid >= nums1.size()) ? INT_MAX: nums1[mid];
            int n2Left = (rem <= 0) ? INT_MIN : nums2[rem-1];
            int n2Right = (rem >= nums2.size()) ? INT_MAX : nums2[rem];

            if(n1Left <= n2Right && n2Left <= n1Right)
            {
                //we have found valid partition

                if(totalSize % 2 == 0)
                {
                    //even amount of elements
                    int one = max(n1Left, n2Left);
                    int two = min(n1Right, n2Right);
                    return (static_cast<double>(one) + static_cast<double>(two)) / 2.0;
                }
                else
                {
                    //odd amount of elements
                    return static_cast<double>(min(n1Right, n2Right));
                }
            }
            else if(n1Left > n2Right)
            {
                //we took too many elements from n1Left so take less
                right = mid-1;

            }
            else
            {
                //n2Left > n1Right
                //we took too many elements in n2Left
                //we have to take more elements 
                left = mid+1;
            }


        }

        return 0.0;
    }
};
