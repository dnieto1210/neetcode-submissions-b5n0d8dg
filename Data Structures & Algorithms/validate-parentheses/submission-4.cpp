class Solution {
public:
    bool isValid(string s) {

        stack<char> myStack;

        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                myStack.push(s[i]);
            }
            else
            {
                if(myStack.empty())
                {
                    return false;
                }
                char check = myStack.top();
                myStack.pop();

                if(s[i] == '}' && check != '{')
                {
                    return false;

                }
                else if(s[i] == ']' && check != '[')
                {
                    return false;

                }
                else if(s[i] == ')' && check != '(')
                {
                    return false;
                }
            }
        }

        if(!myStack.empty())
        {
            return false;
        }

        return true;
        
    }
};
