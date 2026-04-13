class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> myStack;
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); ++i)
        {
            int curr = temperatures[i];
            if(myStack.empty())
            {
                myStack.push({curr, i});
            }
            else
            {
                int num = myStack.top().first;
                while(curr > num)
                {
                    int idx = myStack.top().second;
                    res[idx] = i - idx;
                    myStack.pop();
                    if(myStack.empty())
                    {
                        break;
                    }
                    num = myStack.top().first;
                }

                myStack.push({curr, i});

            }


        }

        return res;
        
    }
};
