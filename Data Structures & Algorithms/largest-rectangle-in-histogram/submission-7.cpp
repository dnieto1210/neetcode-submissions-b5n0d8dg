class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> myStack;
        int largest = 0;

        for(int i = 0; i < heights.size(); ++i)
        {
            int h = heights[i];
            int idx = -1;
            while(!myStack.empty() && heights[myStack.top()] > h)
            {
                idx = myStack.top();
                int pot = heights[idx] * (i-idx);
                largest = max(largest, pot);
                heights[idx] = h;
                myStack.pop();
            }
            if(idx >= 0)
            {
                myStack.push(idx);
            }
            myStack.push(i);
        }

        int size = heights.size();
        while(!myStack.empty())
        {
            int idx = myStack.top();
            int pot = heights[idx] * (size - idx);
            largest = max(largest, pot);
            myStack.pop();
        }

        return largest;
        
    }
};
