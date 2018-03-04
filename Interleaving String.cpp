class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length()+s2.length())
        {
            return false;
        }
        bool dp[s1.length()+1][s2.length()+1];
        for(int iter = 0; iter < s1.length()+1; iter++)
        {
            for(int jter = 0; jter < s2.length()+1; jter++)
            {
                if(iter == 0 && jter == 0)
                {
                    dp[iter][jter] = true;
                }
                else if(iter == 0)
                {
                    dp[iter][jter] = (dp[iter][jter-1] && s2[jter-1] == s3[iter+jter-1]);
                }
                else if(jter == 0)
                {
                    dp[iter][jter] = (dp[iter-1][jter] && s1[iter-1] == s3[iter+jter-1]);
                }
                else
                {
                    dp[iter][jter] = (dp[iter][jter-1] && s2[jter-1] == s3[iter+jter-1]) || (dp[iter-1][jter] && s1[iter-1] == s3[iter+jter-1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];

    }
};
