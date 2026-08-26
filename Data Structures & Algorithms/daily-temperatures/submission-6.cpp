class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {


        vector<int> result(temperatures.size(), 0);
        stack<int> myStack;

        for(int i = 0; i < temperatures.size(); ++i)
        {
            int t = temperatures[i];
            while(!myStack.empty() && t > temperatures[myStack.top()])
            {
                result[myStack.top()] = i - myStack.top();
                myStack.pop();
            }
            myStack.push(i);

        }

        return result;
        
    }
};
