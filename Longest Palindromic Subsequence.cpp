class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();

        /*int **dp = (int **)malloc(sizeof(int ) * len);
        for(int iter = 0; iter < len; iter++)
        {
            dp[iter] = (int *)malloc(sizeof(int) * len);
        }
        for(int iter = 0; iter < len; iter++)
        {
            dp[iter][iter] = 1;
        }
        */
        int dp[len][len];
        for(int iter = 0; iter < len; iter++)
        {
            dp[iter][iter] = 1;
        }

        for(int kter = 2; kter <= len; kter++)
        {
            for(int iter = 0; iter < len-kter+1; iter++)
            {
                int jter = iter+kter-1;
                if(s[iter] == s[jter] && kter == 2)
                {
                    dp[iter][jter] = 2;
                }
                else if(s[iter] == s[jter])
                {
                    dp[iter][jter] = dp[iter+1][jter-1] + 2;
                }
                else{
                    dp[iter][jter] = max(dp[iter+1][jter] , dp[iter][jter-1]);
                }
            }
        }
        return dp[0][len-1];


    }
};
