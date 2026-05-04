class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> myStack;
        int result = 0;
        for(int i = 0; i < tokens.size(); ++i)
        {
            string s = tokens[i];
            if((s != "+") && (s != "-") && (s != "*") && (s != "/"))
            {
                int check = stoi(s);
                myStack.push(check);
            }
            else
            {
                //it is one of the operands
                int second = (!myStack.empty()) ? myStack.top() : 0;
                myStack.pop();
                int first = (!myStack.empty()) ? myStack.top() : 0;
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
        }

        return (!myStack.empty()) ? myStack.top(): 0;
        
    }
};
