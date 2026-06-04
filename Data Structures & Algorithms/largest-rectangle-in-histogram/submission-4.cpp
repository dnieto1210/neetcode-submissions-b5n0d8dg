class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        using Node = pair<int,int>;
        stack<Node> myStack;
        int largestArea = 0;
        for(int i = 0; i < heights.size(); ++i)
        {
            int h = heights[i];
            if(myStack.empty())
            {
                myStack.push({h, i});
            }
            else
            {
                int idx = i;
                while(!myStack.empty() && h <= myStack.top().first)
                {
                    idx = myStack.top().second;
                    int curr_area = myStack.top().first * (i-idx);
                    largestArea = max(largestArea, curr_area);
                    myStack.pop();
                }

                myStack.push({h, idx});
            }
        }

        while(!myStack.empty())
        {
            int h = myStack.top().first;
            int idx = myStack.top().second;
            myStack.pop();
            int curr_area = h * (n-idx);
            largestArea = max(largestArea, curr_area);
        }




        return largestArea;
        
    }
};
