class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<string> myStack;
        for(int i = 0; i < tokens.size(); ++i)
        {
            string s = tokens[i];
            if(s != "+" && s != "-" && s != "*" && s != "/")
            {
                myStack.push(s);
            }
            else
            {
                int one = stoi(myStack.top());
                myStack.pop();
                int two = stoi(myStack.top());
                myStack.pop();
                int res = 0;
                if(s == "+")
                {
                    res = one + two;
                }
                else if(s == "*")
                {
                    res = one * two;
                }
                else if(s == "-")
                {
                    res = two - one;
                }
                else
                {
                    res = two / one;
                }

                myStack.push(to_string(res));
            }
        }

        return stoi(myStack.top());
        
    }
};
