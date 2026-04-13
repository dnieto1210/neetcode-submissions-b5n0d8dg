class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> myStack;

        for(int i = 0; i < tokens.size(); ++i)
        {
            if((tokens[i] != "+") && (tokens[i] != "-") && (tokens[i] != "*") && (tokens[i] != "/"))
            {
                int num = stoi(tokens[i]);
                myStack.push(num);
            }
            else if(tokens[i] == "+")
            {
                int top = myStack.top();
                myStack.pop();
                int bottom = myStack.top();
                myStack.pop();

                int res = top + bottom;
                myStack.push(res);
            }
            else if(tokens[i] == "-")
            {
                int top = myStack.top();
                myStack.pop();
                int bottom = myStack.top();
                myStack.pop();
                int res = bottom - top;
                myStack.push(res);


            }
            else if(tokens[i] == "*")
            {
                int top = myStack.top();
                myStack.pop();
                int bottom = myStack.top();
                myStack.pop();

                int res = top * bottom;
                myStack.push(res);

            }
            else
            {
                //division
                int top = myStack.top();
                myStack.pop();
                int bottom = myStack.top();
                myStack.pop();

                int res = bottom / top;
                myStack.push(res);
            }
        }

        return myStack.top();
        
    }
};
