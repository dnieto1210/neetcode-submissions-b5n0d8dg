class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int j = 0; j < s.size(); ++j)
        {
            for(int i = 0; i < s.size(); ++i)
            {
                if(i == j)
                {
                    dp[i][j] = true;
                }
                else if(i > j)
                {
                    dp[i][j] = false;
                }
                else if(j == (i+1))
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else if(s[i] == s[j])
                {
                    dp[i][j] = dp[i+1][j-1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        int count = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            for(int j = 0; j < s.size(); ++j)
            {
                if(dp[i][j])
                {
                    ++count;
                }
            }
        }

        return count;
        
    }
};
