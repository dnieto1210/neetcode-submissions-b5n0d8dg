class Solution {
public:
    int maxArea(vector<int>& heights) {

        int maxA = INT_MIN;
        int left = 0;
        int right = heights.size()-1;

        while(left < right)
        {
            int width = right - left;
            int height = std::min(heights[left], heights[right]);
            int area = height * width;
            maxA = std::max(maxA, area);

            if(heights[left] == height)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return maxA;
        
    }
};
