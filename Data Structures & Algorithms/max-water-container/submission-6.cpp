class Solution {
public:
    int maxArea(vector<int>& heights) {

        int maxContainer = 0;
        int left = 0;
        int right = heights.size()-1;

        while(left < right)
        {
            int width = right - left;
            int height = min(heights[left], heights[right]);
            int curr = width * height;
            maxContainer = max(maxContainer, curr);

            if(heights[left] < heights[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return maxContainer;
        
    }
};
