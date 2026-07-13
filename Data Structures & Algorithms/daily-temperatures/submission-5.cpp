class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> myStack;
        vector<int> res(temperatures.size(), 0);
        

        int i = 0;
        while(i < temperatures.size())
        {
            int temp = temperatures[i];

            if(myStack.empty())
            {
                myStack.push(i);
            }
            else
            {
                int idx = myStack.top();
                int comp = temperatures[idx];
                while(temp > comp)
                {
                    myStack.pop();
                    res[idx] = i - idx;
                    if(myStack.empty())
                    {
                        break;
                    }
                    else
                    {
                        idx = myStack.top();
                        comp = temperatures[idx];
                    }
                }
                myStack.push(i);
            }

            ++i;
        }

        return res;
        
    }
};
