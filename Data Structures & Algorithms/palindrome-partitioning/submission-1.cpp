class Solution {
public:
    bool isPalidrome(string curr) {
        int left = 0;
        int right = curr.size()-1;
        while(left <= right) {
            if(curr[left] != curr[right]) {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }

    void dfs(int idx, string& s) {
        if(idx >= s.size())
        {
            result.push_back(temp);
            return;
        }

       
        int length = s.size()-idx;
        for(int i = 1; i <= length; ++i)
        {
            string part = s.substr(idx, i);
            if(part.size() < 1)
            {
                continue; 
            }

            if(!isPalidrome(part))
            {
                continue;
            }

            //if we get here we have a string of size > 0 and it is a palidrome
            temp.push_back(part);
            dfs(idx+i, s);
            temp.pop_back();
        }

        return; 

    }
    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return result;
    }
private:
    vector<vector<string>> result;
    vector<string> temp;
};
