class Solution {
public:
    int maxArea(vector<int>& heights) {

        int left = 0;
        int right = heights.size()-1;
        int maxArea = INT_MIN;

        while(left < right)
        {
            int h = min(heights[left], heights[right]);
            int w = right-left;
            int a = h * w;
            maxArea = max(maxArea, a);

            if(heights[left] < heights[right])
            {
                ++left;
            }
            else
            {
                --right;
            }

        }

        return maxArea;
        
    }
};
