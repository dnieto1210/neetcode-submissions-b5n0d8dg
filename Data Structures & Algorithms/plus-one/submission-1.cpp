class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        long long total = 0;
        long long mult = 1;
        for(int i = digits.size()-1; i >= 0; --i)
        {
            int num = digits[i];
            total += (mult * num);
            mult = mult * 10;
        }

        total = total + 1;
        stack<int> myStack;
        while(total > 0)
        {
            int d = total % 10;
            total = total / 10;
            myStack.push(d);
        }

        vector<int> res;
        while(!myStack.empty())
        {
            res.push_back(myStack.top());
            myStack.pop();
        }

        return res;
        
    }
};
