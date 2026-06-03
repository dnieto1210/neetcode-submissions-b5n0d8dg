class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> myStack;
        for(int i = 0; i < tokens.size(); ++i)
        {
            string s = tokens[i];
            if(s == "+" || s == "-" || s == "*" || s == "/")
            {
                int second = myStack.top();
                myStack.pop();
                int first = myStack.top();
                myStack.pop();
                if(s == "+")
                {
                    int result = first + second;
                    myStack.push(result);
                }
                else if(s == "-")
                {
                    int result = first - second;
                    myStack.push(result);
                }
                else if(s == "*")
                {
                    int result = first * second;
                    myStack.push(result);
                }
                else
                {
                    int result = first / second;
                    myStack.push(result);
                }

            }
            else
            {
                int num = stoi(s);
                myStack.push(num);
            }
        }

        return myStack.top();
        
    }
};
