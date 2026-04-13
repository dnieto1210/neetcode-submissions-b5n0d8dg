class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        std::stack<std::pair<int,int>> myStack;

        for(int i = 0; i < heights.size(); ++i)
        {
            int start = i;

            while(!myStack.empty() && myStack.top().second > heights[i])
            {
                int index = myStack.top().first;
                int height = myStack.top().second;
                int width = i - index;
                maxArea = std::max(maxArea, height * width);
                start = index;
                myStack.pop();
            }

            myStack.push({start, heights[i]});
        }

        while(!myStack.empty())
        {
            int height = myStack.top().second;
            int width = heights.size() - myStack.top().first;
            maxArea = std::max(maxArea, height * width);
            myStack.pop();
        }

        return maxArea;
        
    }
};
