class Solution {
public:
    int max(int x, int y)
    {
        return x > y ? x : y;
    }
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
        {
            return 0;
        }
        if(s.length() == 1)
        {
            return 1;
        }
        int iter (0);
        int jter (0);
        int maxLength (0);
        map<char, bool> mp;
        while(iter < s.length() && jter < s.length())
        {
            if(mp[s[jter]] == false)
            {
                mp[s[jter]] = true;
                maxLength = max(maxLength, jter-iter+1);
                jter++;
            }
            else if(mp[s[jter]] == true)
            {
                maxLength = max(maxLength, jter-iter);
                mp[s[iter]] = false;
                iter++;
            }
        }
        return maxLength;

    }
};
