class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> myStack;

        for(int i = 0; i < tokens.size(); ++i)
        {
            string s = tokens[i];

            if(s != "+" && s != "-" && s != "/" && s != "*")
            {
                int num = stoi(s);
                myStack.push(num);
            }
            else
            {
                int right = myStack.top();
                myStack.pop();
                int left = myStack.top();
                myStack.pop();
                int res = 0;
                if(s == "+")
                {
                    res = right + left;
                }
                else if(s == "-")
                {
                    res = left - right;
                }
                else if(s == "*")
                {
                    res = right * left;
                }
                else
                {
                    res = left / right;
                }
                myStack.push(res);
            }
        }

        return (myStack.empty()) ? -1 : myStack.top();
        
    }
};
