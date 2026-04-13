class Solution {
public:

    void backtrack(int n, int left, int right, string& temp, vector<string>& result)
    {
        if(left == 0 && right == 0)
        {
            result.push_back(temp);
            return;
        }

        if(left > 0)
        {
            temp += '(';
            backtrack(n, left-1, right, temp, result);
            temp.pop_back();
        }

        if(right > left)
        {
            temp += ')';
            backtrack(n, left, right-1, temp, result);
            temp.pop_back();
        }

        return;


    }
    vector<string> generateParenthesis(int n) {

        int left = n; 
        int right = n;
        vector<string> result;
        string temp = "";
        backtrack(n, left, right, temp, result);

        return result;
        
    }
};
