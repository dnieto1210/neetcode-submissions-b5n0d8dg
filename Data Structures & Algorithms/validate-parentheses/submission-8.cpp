class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;

        for(int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if(c == '(' || c == '{' || c == '[')
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
                    char left = myStack.top();
                    myStack.pop();
                    if(left == '(' && c == ')')
                    {
                        continue;
                    }
                    else if(left == '{' && c == '}')
                    {
                        continue;
                    }
                    else if(left == '[' && c == ']')
                    {
                        continue;
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
