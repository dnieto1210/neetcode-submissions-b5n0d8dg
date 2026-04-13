class Solution {
public:
    bool isPalidrome(string& s)
    {
        if(s.empty())
        {
            return true;
        }
        //otherwise string is not empty
        int left = 0;
        int right = s.size()-1;
        while(left < right)
        {
            if(s[left] != s[right])
            {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }

    void dfs(vector<vector<string>>& result, vector<string>& temp, int idx, string& s)
    {
        if(idx >= s.size())
        {
            result.push_back(temp);
            return;
        }


        for(int i = idx; i < s.size(); ++i)
        {
            //vector<string> temp;
            int size = i -idx + 1;
            string ch = s.substr(idx, size);
            //check if palidrome
            bool check = isPalidrome(ch);
            if(check)
            {
                temp.push_back(ch);
                dfs(result, temp, i+1, s);
                temp.pop_back();
            }
            else
            {
                //not a palidrome 
                //skip to next
                continue;
            }

        }

    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> result;
        vector<string> temp;
        dfs(result, temp, 0, s);

        return result;
        
    }
};
