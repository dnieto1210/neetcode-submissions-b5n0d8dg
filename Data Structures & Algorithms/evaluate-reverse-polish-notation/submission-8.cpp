class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> myStack;

        for(int i = 0; i < tokens.size(); ++i)
        {
            string curr = tokens[i];
            if(curr == "+" || curr == "-" || curr == "*" || curr == "/")
            {
                int one = myStack.top();
                myStack.pop();
                int second = myStack.top();
                myStack.pop();
                if(curr == "+")
                {
                    myStack.push(one + second);
                }
                else if(curr == "-")
                {
                    myStack.push(second - one);
                }
                else if(curr == "*")
                {
                    myStack.push(one * second);
                }
                else
                {
                    myStack.push(second / one);
                }
            }
            else
            {
                //it is a number string so convert to int
                myStack.push(stoi(curr));
            }
        }

        return myStack.top();
    }
};
