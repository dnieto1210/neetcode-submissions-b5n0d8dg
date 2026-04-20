class Solution {
public:
    int numDistinct(string s, string t) {

        int s_size = s.size();
        int t_size = t.size();
        if(s_size < t_size)
        {
            return 0;
        }

        vector<vector<int>> dp(s_size+1, vector<int>(t_size+1, 0));

        for(int i = s_size-1; i >= 0; --i)
        {
            for(int j = t_size-1; j >= 0; --j)
            {
                if(i >= s_size)
                {
                    dp[i][j]= 0;
                }
                else if(s[i] == t[j] && j == t_size-1)
                {
                    dp[i][j] = 1 + dp[i+1][j];
                }
                else if(s[i] == t[j])
                {
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                }
                else if(s[i] != t[j])
                {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }

        return dp[0][0];
        
    }
};
