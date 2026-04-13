#include <string>
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
            else if(s == "+")
            {
                //pop twice
                string first = myStack.top();
                myStack.pop();
                string second = myStack.top();
                myStack.pop();

                int a = stoi(second);
                int b = stoi(first);

                int result = a + b;
                string r = to_string(result);
                myStack.push(r);
            }
            else if(s == "-")
            {
                //pop twice
                string first = myStack.top();
                myStack.pop();
                string second = myStack.top();
                myStack.pop();

                int a = stoi(second);
                int b = stoi(first);

                int result = a - b;
                string r = to_string(result);
                myStack.push(r);

            }
            else if(s == "*")
            {
                //pop twice
                string first = myStack.top();
                myStack.pop();
                string second = myStack.top();
                myStack.pop();

                int a = stoi(second);
                int b = stoi(first);

                int result = a * b;
                string r = to_string(result);
                myStack.push(r);

            }
            else if(s == "/")
            {
                //pop twice
                string first = myStack.top();
                myStack.pop();
                string second = myStack.top();
                myStack.pop();

                int a = stoi(second);
                int b = stoi(first);

                int result = a / b;
                string r = to_string(result);
                myStack.push(r);

            }
        }

        int result = stoi(myStack.top());
        return result;
        
    }
};
