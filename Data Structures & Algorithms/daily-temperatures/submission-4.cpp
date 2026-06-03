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
                int check = temperatures[idx];
                while(temp > check)
                {
                    result[idx] = i - idx;
                    myStack.pop();
                    if(!myStack.empty())
                    {
                        idx = myStack.top();
                        check = temperatures[idx];
                    }
                    else
                    {
                        break;
                    }
                }
                myStack.push(i);
            }
        }

        return result;
        
    }
};
