class Solution {
public:
    int trap(vector<int>& height) {

        int maxLeft = height[0];
        int left = 0;
        int right = height.size()-1;
        int maxRight = height[right];
        int total_water = 0;

        while(left < right)
        {
            if(maxLeft < maxRight)
            {
                ++left;
                maxLeft = std::max(height[left], maxLeft);
                total_water += maxLeft - height[left];
            }
            else
            {
                //maxRight <= maxLeft
                --right;
                maxRight = std::max(maxRight, height[right]);
                total_water += maxRight - height[right];
            }
        }

        return total_water;
        
    }
};
