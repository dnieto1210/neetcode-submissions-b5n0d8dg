class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = INT_MIN;

        int left = 0;
        int right = heights.size()-1;

        while(left < right)
        {
            int width = right - left;
            int height = std::min(heights[left], heights[right]);

            int area = width * height;
            if(area > max)
            {
                max = area;
            }

            if(heights[left] < heights[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return max;
        
    }
};
