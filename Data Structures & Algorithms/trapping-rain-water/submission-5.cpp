class Solution {
public:
    int trap(vector<int>& height) {


        int left = 0;
        int right = height.size()-1;
        int prevLeft = height[0];
        int prevRight = height[right];
        int total = 0;

        while(left < right)
        {
            if(height[left] < height[right])
            {
                ++left;
                prevLeft = max(prevLeft, height[left]);
                total += (prevLeft - height[left]);
            }
            else
            {
                --right;
                prevRight = max(prevRight, height[right]);
                total += (prevRight - height[right]);

            }
        }
        return total;
        
    }
};
