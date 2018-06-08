class Solution {
public:
    int numDistinct(string s, string t)
    {
       int len_S = s.length();
    int len_T = t.length();

    vector<vector<int> > dp(len_S+1, vector<int>(len_T+1, 0));
  /* int **dp = (int **)malloc(sizeof(int) * len_S+1);
   for(int iter = 0; iter <= len_T; iter++)
   {
       dp[iter] = (int *)malloc(sizeof(int) * len_T+1);
   }
   for(int iter = 0; iter <= len_S; iter++)
   {
       for(int jter = 0; jter <= len_T; jter++)
       {
           dp[iter][jter] = 0;
       }
   }*/
    for(int iter = 0; iter <= len_S; iter++)
    {
        dp[iter][0] = 1;
    }

    for(int iter = 1; iter <= len_S; iter++)
    {
        for(int jter = 1; jter <= len_T; jter++)
        {
            if(s[iter-1] == t[jter-1])
            {
                dp[iter][jter] = dp[iter][jter] + dp[iter-1][jter] + dp[iter-1][jter-1];
            }
            else
            {
                dp[iter][jter] += dp[iter-1][jter];
            }
        }
    }
   return dp[len_S][len_T];


    }
};
