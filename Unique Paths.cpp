class Solution {
public:
    int uniquePaths(int m, int n) {
    /*    long long int ans (1);
        for(int iter = n; iter < (m+n-1); iter++)
        {
            ans = ans *iter;
            ans = ans / (iter-n+1);
        }
        return (int)ans;*/

        int NumWays[m][n];
        NumWays[0][0] = 1;
        for(int jter = 1; jter < n; jter++)
        {
            NumWays[0][jter] = 1;
        }

        for(int iter = 1; iter < m; iter++)
        {
            NumWays[iter][0] = 1;
        }

        for(int iter = 1; iter < m; iter++)
        {
            for(int jter = 1; jter < n; jter++)
            {
                NumWays[iter][jter] = NumWays[iter-1][jter] + NumWays[iter][jter-1];
            }
        }

        return NumWays[m-1][n-1];
    }
};
