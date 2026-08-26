class Solution {
public:
    bool isValid(string s) {


        stack<char> myStack;

        for(int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if(c == '[' || c == '(' || c == '{')
            {
                myStack.push(c);
            }
            else
            {
                if(myStack.empty())
                {
                    return false;
                }
                else
                {
                    char check = myStack.top();
                    myStack.pop();
                    if((c == ')' && check != '(') || (c == ']' && check != '[') || (c == '}' && check != '{'))
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
        return false;
        
    }
};
