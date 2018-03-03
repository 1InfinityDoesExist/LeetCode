class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();

        int i, j , istart = -1, jstart = -1;

        for(i = 0, j = 0; i < slen; i++, j++)
        {
            if(p[j] == '*')
            {
                istart = i;
                jstart = j;
                --i;
            }
            else
            {
                if(p[j] != s[i] && p[j] != '?')
                {
                    if(istart >= 0)
                    {
                        i = istart++;
                        j = jstart;
                    }
                    else
                    {
                        return false;
                    }
                }
            }

        }
             while(p[j] == '*')
            {
                j++;
            }
            return j == plen;

    }
};
