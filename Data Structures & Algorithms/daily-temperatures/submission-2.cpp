class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        using Node = pair<int,int>;
        stack<Node> myStack;
        vector<int> result(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); ++i)
        {
            int temp = temperatures[i];
            while(!myStack.empty() && myStack.top().first < temp)
            {
                int idx = myStack.top().second;
                int days = i - idx;
                result[idx] = days;
                myStack.pop();
            }
            myStack.push({temp, i});
        }

        return result;
        
    }
};
