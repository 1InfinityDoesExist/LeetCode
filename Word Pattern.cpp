class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> v;
        string s = "";
        map<string, int> ms;
        for(string::size_type iter = 0; iter < str.length(); iter++)
        {
            if(str[iter] == ' ')
            {
                if(s.length() == 0)
                {
                    continue;
                }
                else
                {
                    v.push_back(s);
                    ms[s]++;
                    s = "";
                }
            }
            else
            {
                s = s+str[iter];
                if(iter == str.length()-1)
                {
                    ms[s]++;
                    v.push_back(s);
                }
            }
        }
        if(pattern.length() != v.size() )
        {
            return false;
        }
        map<char, int> mc;
        for(string::size_type iter = 0; iter < pattern.length(); iter++)
        {
            mc[pattern[iter]]++;
        }
        if(mc.size() != ms.size())
        {
            return false;
        }
        int i (0);
        map<char, string > mp;
        for(string::size_type iter = 0; iter < pattern.length(); iter++)
        {
            if(mp.find(pattern[iter]) != mp.end())
            {
                if(mp[pattern[iter]] == v[i])
                {
                    i++;
                }
                else
                {
                    return false;
                }

            }
            else
            {
                mp[pattern[iter]] = v[i++];
            }
        }
        return true;
    }
};
