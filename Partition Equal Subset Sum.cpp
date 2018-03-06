class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum (0);
        for(int iter = 0; iter < nums.size(); iter++)
        {
            sum = sum + nums[iter];
        }
        if(sum%2 != 0)
        {
            return false;
        }
        int n = nums.size();
        bool dp[sum/2 + 1][n+1];
        for(int iter = 0; iter <= n; iter++)
        {
            dp[0][iter] = true;
        }

        for(int jter = 1; jter <= sum/2; jter++)
        {
            dp[jter][0] = false;
        }

        for(int iter = 1; iter <= sum/2; iter++)
        {
            for(int jter = 1; jter <= n; jter++)
            {
                dp[iter][jter] = dp[iter][jter-1];
                if(iter >= nums[jter-1])
                {
                    dp[iter][jter] = dp[iter][jter] || dp[iter - nums[jter-1]][jter-1];
                }

            }
        }

        return dp[sum/2][n];

    }
};
