class Solution {
public:

    void backtrack(int left, int right, int n, std::vector<std::string>& result, std::string s)
    {
        if(left == n && left == right)
        {
            result.push_back(s);
            return;
        }

        if(left < n)
        {
            s += '(';
            backtrack(left+1, right, n, result, s);
            s.pop_back();
        }

        if(right < left)
        {
            s += ')';
            backtrack(left, right+1, n, result, s);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string s= "";
        backtrack(0,0,n,result, s);

        return result;

        
    }
};
