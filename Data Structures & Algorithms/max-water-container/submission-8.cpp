class Solution {
public:
    int maxArea(vector<int>& heights) {

        int maxWater = 0;
        int left = 0;
        int right = heights.size()-1;
        while(left < right)
        {
            int w = right - left;
            int h = min(heights[left], heights[right]);
            int area = w * h;
            maxWater = max(maxWater, area);

            if(heights[left] < heights[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return maxWater;
        
    }
};
