class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(),0);
        std::stack<int> myStack;

        for(int i = 0; i < temperatures.size(); ++i)
        {

            while(!myStack.empty() && temperatures[i] > temperatures[myStack.top()])
            {
                int days = i - myStack.top();
                result[myStack.top()] = days;
                myStack.pop();
            }
            myStack.push(i);
        }

        return result;
        
    }
};
