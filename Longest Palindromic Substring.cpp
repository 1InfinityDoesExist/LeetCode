class Solution {
public:
    string longestPalindrome(string s) {
      int n = s.length();
        bool table[n][n];
        memset(table, 0, sizeof(table));
        int maxlength = 1;
        for(int iter = 0; iter < n; iter++)
        {
            table[iter][iter] = true;
        }

        int start = 0;
        for(int iter = 0; iter < n-1; iter++)
        {
            if(s[iter] == s[iter+1])
            {
                table[iter][iter+1] = true;
                start = iter;
                maxlength = 2;
            }
        }

        for(int k = 3; k <= n; k++)
        {
            for(int iter = 0; iter < n-k+1; iter++)
            {
                int jter = iter+k-1;
                if(table[iter+1][jter-1] && s[iter] == s[jter])
                {
                    table[iter][jter] = true;
                    if( k > maxlength)
                    {
                        start = iter;
                        maxlength = k;
                    }
                }
            }
        }
        cout << maxlength << start;
       // return maxlength;
        string ktr = "";
        for(int iter = start; iter <= start+maxlength-1; iter++)
        {
            ktr = ktr+s[iter];
        }
      //  return s.substr(start, maxlength-1);
        return ktr;

    }
};
