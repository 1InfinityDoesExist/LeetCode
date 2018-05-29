#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int winAGame(const int n);
};
Solution::Solution(){}
int Solution::winAGame(const int n)
{
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int iter = 3; iter <= n; iter++)
    {
        dp[iter] = dp[iter] + dp[iter-3];
    }
    for(int iter = 5; iter <= n; iter++)
    {
        dp[iter] = dp[iter] + dp[iter-5];
    }
    for(int iter = 10; iter <= n; iter++)
    {
        dp[iter] = dp[iter] + dp[iter-10];
    }
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {

       int n;
       cin >> n;
        int ans = sol.winAGame(n);
        cout << ans << endl;
    }
    return 0;
}
