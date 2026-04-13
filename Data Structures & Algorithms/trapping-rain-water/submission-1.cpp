class Solution {
public:
    int trap(vector<int>& height) {
        //two pointers method
        int left = 0;
        int right = height.size()-1;
        int leftMax = 0;
        int rightMax = 0;
        int total_water = 0;

        while(left < right)
        {
            if(height[left] < height[right])
            {
                leftMax = std::max(leftMax, height[left]);
                total_water += leftMax - height[left];
                ++left;
            }
            else
            {
                rightMax = std::max(rightMax, height[right]);
                total_water += rightMax - height[right];
                --right;
            }
        }

        return total_water;
        
    }
};
