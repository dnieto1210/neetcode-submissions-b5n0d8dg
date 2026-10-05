class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> myStack;
        for(int i = 0; i < temperatures.size(); ++i)
        {
            while(!myStack.empty() && temperatures[myStack.top()] < temperatures[i])
            {
                result[myStack.top()] = i- myStack.top();
                myStack.pop();
            }
            myStack.push(i);
        }
        return result;
        
    }
};
