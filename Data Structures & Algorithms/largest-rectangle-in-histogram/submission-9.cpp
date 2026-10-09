class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> myStack;
        int largestA = 0;
        for(int i = 0; i < heights.size(); ++i)
        {
            int curr = heights[i];
            int idx = i;
            while(!myStack.empty() && heights[myStack.top()] > curr)
            {
                int pot = (i-myStack.top()) * heights[myStack.top()];
                largestA = max(pot, largestA);
                idx = myStack.top();
                myStack.pop();
            }
            heights[idx] = curr;
            myStack.push(idx);
        }

        int n = heights.size();
        while(!myStack.empty())
        {
            int pot = (n-myStack.top()) * heights[myStack.top()];
            largestA = max(pot, largestA);
            myStack.pop();
        }
        return largestA;
        
    }
};
