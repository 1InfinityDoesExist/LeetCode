class Solution {
public:
    int numTrees(int n) {
        int *dp = (int *)malloc(sizeof(int) * n+1);
        for(int iter = 0; iter <= n; iter++)
        {
            dp[iter] = 0;
        }
        dp[0] = dp[1] = 1;
        for(int iter = 2; iter <= n; iter++)
        {
            for(int jter = 1; jter <= iter/2; jter++)
            {
                dp[iter] += dp[jter-1]*dp[iter-jter];
            }
            dp[iter] *= 2;
            if(iter%2)
            {
                dp[iter] += dp[iter/2]*dp[iter/2];
            }

        }
        int ans = dp[n];
        free(dp);
        return ans;
    }
};
