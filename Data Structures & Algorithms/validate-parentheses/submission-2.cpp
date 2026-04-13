class Solution {
public:
    bool isValid(string s) {
        std::stack<char> myStack;

        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                myStack.push(s[i]);
            }
            else
            {
                if(!myStack.empty())
                {
                    char c = myStack.top();
                    myStack.pop();
                    if(c == '(' && s[i] != ')')
                    {
                        return false;
                    }
                    else if(c == '{' && s[i] != '}')
                    {
                        return false;
                    }
                    else if(c == '[' && s[i] != ']')
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return (myStack.empty());
    }
};
