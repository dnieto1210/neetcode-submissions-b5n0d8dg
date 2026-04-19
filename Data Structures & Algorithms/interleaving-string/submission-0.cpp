class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size();
        int m = s2.size(); 
        int z = s3.size();
        if(n + m != z)
        {
            return false;
        }

        vector<vector<bool>> dp(s2.size()+1, vector<bool>(s1.size()+1, false));

        for(int i = m; i >= 0; --i)
        {
            for(int j = n; j >= 0; --j)
            {
                if(i >= m && j >= n && (i +j) >= z)
                {
                    dp[i][j] = true;
                }
                else if(s1[j] != s3[i+j] && s2[i] != s3[i+j])
                {
                    dp[i][j] = false;
                }
                else if(s1[j] != s3[i+j] && s2[i] == s3[i+j])
                {
                    dp[i][j] = dp[i+1][j];
                }
                else if(s1[j] == s3[i+j] && s2[i] != s3[i+j])
                {
                    dp[i][j] = dp[i][j+1];
                }
                else
                {
                    //both are equal
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
                }
            }
        }

        return dp[0][0]; 
    }
};
