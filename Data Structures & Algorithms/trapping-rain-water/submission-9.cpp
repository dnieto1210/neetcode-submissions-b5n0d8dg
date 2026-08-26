class Solution {
public:
    int trap(vector<int>& height) {


        int left = 0;
        int right = height.size()-1;

        int maxLeft = height[left];
        int maxRight = height[right];
        int total = 0;

        while(left < right)
        {
            if(maxLeft < maxRight)
            {
                ++left;
                maxLeft = max(maxLeft, height[left]);
                total += (maxLeft - height[left]);

            }
            else
            {
                //maxLeft >= maxRight
                --right;
                maxRight = max(maxRight, height[right]);
                total += (maxRight - height[right]);
            }

        }

        return total;
        
    }
};
