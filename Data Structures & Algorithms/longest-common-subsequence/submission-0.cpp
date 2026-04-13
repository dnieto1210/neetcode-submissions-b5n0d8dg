class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        std::vector<std::vector<int>> dp(text1.size()+1, std::vector<int>(text2.size()+1,0));
        int n = text1.size();
        int m = text2.size();

        for(int i = text1.size()-1; i >= 0; --i)
        {
            for(int j = text2.size()-1; j >= 0; --j)
            {
                if(i >= n || j >= m)
                {
                    dp[i][j] = 0;
                }
                else if(text1[i] == text2[j])
                {
                    dp[i][j]= max({1+dp[i+1][j+1], dp[i][j+1], dp[i+1][j]});
                }
                else
                {
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
                
            }
        }

        return dp[0][0];
        
    }
};
