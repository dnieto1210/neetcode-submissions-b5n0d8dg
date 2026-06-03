class Solution {
public:
    int trap(vector<int>& height) {


        int left = 0;
        int right = height.size()-1;
        int bestLeft = height[left];
        int bestRight = height[right];
        int max_water = 0;

        while(left < right)
        {
            if(bestLeft < bestRight)
            {
                ++left;
                bestLeft = max(bestLeft, height[left]);
                max_water += (bestLeft - height[left]);

            }
            else
            {
                --right;
                bestRight = max(bestRight, height[right]);
                max_water += (bestRight - height[right]);
            }
        }

        return max_water;
        
    }
};
