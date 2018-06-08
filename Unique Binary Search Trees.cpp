class Solution {
public:
    int numTrees(int n) {
        long long int *dp = (long long int *)malloc(sizeof(long long int) * n+1);
        dp[0] = dp[1] = 1;
        for(int iter = 2; iter <= n; iter++)
        {
            for(int jter = 1; jter <= iter; jter++)
            {
                dp[iter] += dp[jter-1]*dp[iter-jter];
            }
        }
        long long int ans = dp[n];
        free(dp);
        return ans;
    }
};
