class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size()-1;
        int maxLeft = height[left];
        int maxRight = height[right];
        int contains = 0;

        while(left < right)
        {
            if(maxLeft < maxRight)
            {
                ++left;
                maxLeft = max(maxLeft, height[left]);
                contains += maxLeft - height[left];
            }
            else
            {
                --right;
                maxRight = max(maxRight, height[right]);
                contains += maxRight - height[right];
            }
        }

        return contains;
        
    }
};
