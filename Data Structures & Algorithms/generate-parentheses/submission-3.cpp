class Solution {
public:
    void dfs(int left, int right) {
        if(left == 0 && right == 0)
        {
            result.push_back(temp);
        }

        //we know right will never be less than left

        if(left == right)
        {
            //we must take left parent
            temp.push_back('(');
            --left;
            dfs(left, right);
            temp.pop_back();
            ++left;
        }

        if(left < right && left > 0)
        {
            //we can still take a left 
            temp.push_back('(');
            --left;
            dfs(left, right);
            temp.pop_back();
            ++left;

            //or it can take a right
            temp.push_back(')');
            --right;
            dfs(left, right);
            temp.pop_back();
            ++right;
        }

        if(left < right && left == 0)
        {
            //we just take right we cannot take more lefts
            temp.push_back(')');
            --right;
            dfs(left, right);
            temp.pop_back();
            ++right;
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return result;
    }
private:
    vector<string> result;
    string temp;
};
