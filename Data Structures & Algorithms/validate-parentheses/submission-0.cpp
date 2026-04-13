class Solution {
public:
    bool isValid(string s) {

        std::stack<char> myStack;
        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                myStack.push(s[i]);
            }
            else
            {
                //s[i] is the right side of the grouping symbol
                if(myStack.empty())
                {
                    return false;
                }
                else
                {
                    char check = myStack.top();
                    if(check == '(' && s[i] == ')')
                    {
                        myStack.pop();
                    }
                    else if(check == '{' && s[i] == '}')
                    {
                        myStack.pop();
                    }
                    else if(check == '[' && s[i] == ']')
                    {
                        myStack.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        if(myStack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};
