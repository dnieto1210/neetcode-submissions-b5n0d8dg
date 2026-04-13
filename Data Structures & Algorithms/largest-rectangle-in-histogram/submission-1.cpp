class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> myStack;
        int maxArea = INT_MIN;

        for(int i = 0; i < heights.size(); ++i)
        {
            int h = heights[i];
            int idx = i;
            while(!myStack.empty() && h < myStack.top().first)
            {
                pair<int,int> p = myStack.top();
                myStack.pop();
                int pot_area = (i - p.second) * p.first;
                maxArea = max(maxArea, pot_area);
                idx = p.second;
            }

            myStack.push({h, idx});
        }

        while(!myStack.empty())
        {
            pair<int,int> p = myStack.top();
            myStack.pop();
            int pot_area = (heights.size()- p.second) * p.first;
            maxArea = max(maxArea, pot_area);
        }

        return maxArea;
        
    }
};
