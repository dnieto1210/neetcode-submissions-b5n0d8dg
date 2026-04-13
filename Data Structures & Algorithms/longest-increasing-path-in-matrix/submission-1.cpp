class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col)
    {
        if(row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size())
        {
            return 0;
        }
        //otherwise its valid
        if(dp[row][col] != 0)
        {
            return dp[row][col];
        }

        int best = 1;

        //otherwise its zero and we have to find longest path given that cell
        //check up, down, left, right
        if(row-1 >= 0 && matrix[row-1][col] > matrix[row][col])
        {
            best = max(best, 1 + dfs(matrix, dp, row-1, col));
        }

        if(row+1 < matrix.size() && matrix[row+1][col] > matrix[row][col])
        {
            best = max(best, 1 + dfs(matrix, dp, row+1, col));
        }

        if(col-1 >= 0 && matrix[row][col-1] > matrix[row][col])
        {
            best = max(best,1 +  dfs(matrix, dp, row, col-1));
        }

        if(col+1 < matrix[0].size() && matrix[row][col+1] > matrix[row][col])
        {
            best = max(best, 1 + dfs(matrix, dp, row, col+1));
        }

        dp[row][col] = best;

        return dp[row][col];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_count = 0;
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                int pot = dfs(matrix, dp, i, j);
                max_count = max(max_count, pot);
            }
        }

        return max_count;

        
    }
};
