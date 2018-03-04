class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int iter = 1; iter <= m; iter++)
        {
            dp[iter][0] = iter;
        }
        for(int jter = 1; jter <= n; jter++)
        {
            dp[0][jter] = jter;
        }

        for(int iter = 1; iter <= m; iter++)
        {
            for(int jter = 1; jter <= n; jter++)
            {
                if(word1[iter-1] == word2[jter-1])
                {
                    dp[iter][jter] = dp[iter-1][jter-1];
                }
                else
                {
                    dp[iter][jter] = 1 + min(dp[iter-1][jter-1], min(dp[iter][jter-1], dp[iter-1][jter]));
                }
            }
        }

        return dp[m][n];
    }
};
