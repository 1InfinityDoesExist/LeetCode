class Solution {
public:
    string reverseVowels(string s)
    {
        map<char, int> mp;
        mp['a'] = 1;
        mp['e'] = 1;
        mp['i'] = 1;
        mp['o'] = 1;
        mp['u'] = 1;
        mp['A'] = 1;
        mp['E'] = 1;
        mp['I'] = 1;
        mp['O'] = 1;
        mp['U'] = 1;

        string str = "";
        for(string::size_type iter = 0; iter < s.length(); iter++)
        {
            if(mp.find(s[iter]) != mp.end())
            {
                str += s[iter];
                s[iter] = '~';
            }
            else
            {
                continue;
            }
        }

      //  reverse(str.begin(), str.end());
        for(string::size_type iter = 0; iter < s.length(); iter++)
        {
            if(s[iter] == '~')
            {
                s[iter] = str.back();
                str.pop_back();
            }
        }
        return s;
    }
};
