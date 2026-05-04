class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> myStack;
        vector<int> result(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); ++i)
        {
            int temp = temperatures[i];
            if(myStack.empty())
            {
                myStack.push(i);
            }
            else
            {
                int idx = myStack.top();
                while(temp > temperatures[idx])
                {
                    result[idx] = i - idx;
                    myStack.pop();
                    if(myStack.empty())
                    {
                        break;
                    }
                    else
                    {
                        idx = myStack.top();
                    }

                }

                myStack.push(i);
            }

        }

        return result;
        
    }
};
