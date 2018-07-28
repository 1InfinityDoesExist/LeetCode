class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int sum = 0;
        for(string::size_type iter = 0; iter < s.length()-1; iter++)
        {
            if(mp[s[iter]] >= mp[s[iter+1]])
            {
                sum = sum + mp[s[iter]];
            }
            else
            {
                sum = sum - mp[s[iter]];
            }
        }
        sum = sum + mp[s[s.length()-1]];
        return sum;

    }
};
