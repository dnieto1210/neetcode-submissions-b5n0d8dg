class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> myStack;
        int maxArea = INT_MIN;

        for(int i = 0; i < heights.size(); ++i)
        {
            int idx = i;
            while(!myStack.empty() && heights[i] < myStack.top().first)
            {
                pair<int,int> curr = myStack.top();
                myStack.pop();
                int pot_area = (i - curr.second) * curr.first;
                maxArea = max(maxArea, pot_area);
                idx = curr.second;
            }
            myStack.push({heights[i], idx});
        }

        while(!myStack.empty())
        {
            pair<int,int> curr = myStack.top();
            myStack.pop();
            int length = heights.size();
            int pot_area = (length - curr.second) * curr.first;
            maxArea = max(maxArea, pot_area);
        }

        return maxArea;
        
    }
};
