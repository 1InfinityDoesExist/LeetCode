class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int res (0);

        bool table[n][n];
        memset(table, false, sizeof(table));

        for(int iter = n-1; iter >= 0; iter--)
        {
            for(int jter = iter; jter < n; jter++)
            {
                table[iter][jter] = s[iter] == s[jter] && (jter - iter < 3 || table[iter+1][jter-1]);
                if(table[iter][jter])
                {
                    res++;
                }
            }

        }
        return res;


    }
};
