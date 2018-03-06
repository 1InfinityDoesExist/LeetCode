class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max = amount+1;
        vector<int> dp(amount+1, max);
        dp[0] = 0;
        for(int iter = 1; iter < amount+1; iter++)
        {
            for(int jter = 0; jter < coins.size(); jter++)
            {
                if(coins[jter] <= iter)
                {
                    dp[iter] = min(dp[iter], dp[iter - coins[jter]] +1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];

    }
};
