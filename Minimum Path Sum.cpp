class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dp[m][n];
        dp[0][0] = grid[0][0];
        for(int iter = 1; iter < m; iter++)
        {
            dp[iter][0] = dp[iter-1][0] + grid[iter][0];
        }
        for(int jter = 1; jter < n; jter++)
        {
            dp[0][jter] = dp[0][jter-1] + grid[0][jter];
        }

        for(int iter = 1; iter < m; iter++)
        {
            for(int jter = 1; jter < n; jter++)
            {
                dp[iter][jter] = min(dp[iter-1][jter], dp[iter][jter-1]) + grid[iter][jter];
            }
        }

        return dp[m-1][n-1];
    }
};
