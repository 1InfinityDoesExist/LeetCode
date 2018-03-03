class Solution {
public:

    bool isValid(string str)
    {
        string cp = str;
        sort(str.begin(), str.end());
        str.erase(unique(str.begin(), str.end()), str.end());
        if(cp.length() == str.length())
        {
            return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s)
    {
        if(isValid(s))
        {
            return s.length();
        }
        for(int kter = s.length()-1; kter > 0; kter--)
        {
            for(int iter = 0; iter < s.length()-kter+1; iter++)
            {
                if(isValid(s.substr(iter, kter)))
                {
                    return kter;
                }
            }
        }

    }
};
