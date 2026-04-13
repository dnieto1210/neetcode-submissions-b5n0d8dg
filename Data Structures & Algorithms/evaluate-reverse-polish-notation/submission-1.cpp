#include <cctype>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> myStack;
        int result = 0;
        int first_number = 0;
        int second_number = 0;

        for(int i = 0; i < tokens.size(); ++i)
        {
            if(!(tokens[i] == "+") && !(tokens[i] == "-") && !(tokens[i] == "*") && !(tokens[i] == "/"))
            {
                myStack.push(stoi(tokens[i]));
            }
            else if(tokens[i] == "+")
            {
                second_number = myStack.top();
                myStack.pop();
                first_number = myStack.top();
                myStack.pop();
                result = first_number + second_number;
                myStack.push(result);
            }
            else if(tokens[i] == "-")
            {
                second_number = myStack.top();
                myStack.pop();
                first_number = myStack.top();
                myStack.pop();
                result = first_number - second_number;
                myStack.push(result);

            }
            else if(tokens[i] == "*")
            {
                second_number = myStack.top();
                myStack.pop();
                first_number = myStack.top();
                myStack.pop();
                result = first_number * second_number;
                myStack.push(result);

            }
            else if(tokens[i] == "/")
            {
                second_number = myStack.top();
                myStack.pop();
                first_number = myStack.top();
                myStack.pop();
                result = first_number / second_number;
                myStack.push(result);
            }
        }
        return myStack.top();
        
    }
};
