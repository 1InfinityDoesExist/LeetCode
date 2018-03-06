class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
        {
            return 1;
        }
        if(coins.size() == 0)
        {
            return 0;
        }
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int iter = 0; iter < coins.size(); iter++)
        {
            for(int jter = coins[iter]; jter < amount+1; jter++)
            {
                dp[jter] = dp[jter] + dp[jter - coins[iter]];
            }
        }
        return dp[amount];
    }
};
