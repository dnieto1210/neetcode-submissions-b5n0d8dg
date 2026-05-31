class Solution {
public:
    int maxArea(vector<int>& heights) {

        int left = 0;
        int right = heights.size()-1;
        int max_area = 0;

        while(left < right)
        {
            int curr = min(heights[left], heights[right]) * (right-left);
            max_area = max(max_area, curr);
            if(heights[left] < heights[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return max_area;
        
    }
};
