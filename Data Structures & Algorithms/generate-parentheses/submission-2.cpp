class Solution {
public:
    void backtracking(int left, int right)
    {
        if(left == 0 && right == 0)
        {
            result.push_back(temp);
            return;
        }

        if(left == right)
        {
            temp.push_back('(');
            left -= 1;
            backtracking(left, right);
            ++left;
            temp.pop_back();
            return;

        }


        if(left < right && left > 0)
        {
            temp.push_back('(');
            left -= 1;
            backtracking(left, right);
            ++left;
            temp.pop_back();
            temp.push_back(')');
            right -= 1;
            backtracking(left, right);
            ++right;
            temp.pop_back();
            return;

        }

        if(left < right && left == 0)
        {
            --right;
            temp.push_back(')');
            backtracking(left, right);
            ++right;
            temp.pop_back();
            return;
        }

        return;
        
    }
    vector<string> generateParenthesis(int n) {
        temp = "";
        backtracking(n, n);
        return result;
    }
private:
    vector<string> result;
    string temp;
};
