class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {


        stack<pair<int,int>> myStack;
        int largest = 0;
        int n = heights.size();

        for(int i = 0; i < heights.size(); ++i)
        {
            int h = heights[i];
            if(myStack.empty())
            {
                myStack.push({h,i});
            }
            else
            {
                pair<int, int> check = myStack.top();
                int check_height = check.first;
                int check_idx = check.second;

                if(h > check_height)
                {
                    myStack.push({h, i});
                }
                else if(h < check_height)
                {
                    while(!myStack.empty() && h < myStack.top().first)
                    {
                        check_idx = myStack.top().second;
                        int width = i - check_idx;
                        check_height = myStack.top().first;
                        int pot = check_height * width;
                        largest = max(largest, pot);
                        myStack.pop();
                    }

                    myStack.push({h, check_idx});
                }
                else
                {
                    //h == check_height so we do nothing 
                }
            }
        }

        while(!myStack.empty())
        {
            int idx = myStack.top().second;
            int h = myStack.top().first;
            int width = n - idx;
            int pot = h * width;
            largest = max(largest, pot);
            myStack.pop();
        }

        return largest;
        
    }
};
