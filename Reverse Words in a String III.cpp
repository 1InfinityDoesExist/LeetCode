class Solution {
public:
    string reverseWords(string s) {
        queue<string> qs;
        string current = "";
        for(string::size_type iter = 0; iter < s.length(); iter++)
        {
            if(s[iter] == ' ')
            {
                if(current.length() == 0)
                {
                    continue;
                }
                else
                {
                    reverse(current.begin(), current.end());
                    qs.push(current);
                    current = "";
                }
            }
            else
            {
                current = current + s[iter];
                if(iter == s.length()-1)
                {
                    reverse(current.begin(), current.end());
                    qs.push(current);
                }
            }
        }
        s.erase(s.begin(), s.end());
        while(!qs.empty())
        {
            if(qs.size()-1 == 0)
            {
                 s = s + qs.front();
                qs.pop();
            }
            else
            {
                s = s + qs.front();
                qs.pop();
                s = s + ' ';
            }
        }
        return s;

    }
};
