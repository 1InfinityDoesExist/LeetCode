class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1)
        {
            return false;
        }
        stack<char> sc;
        map<char , char > mc;
        mc['('] = ')';
        mc['{'] = '}';
        mc['['] = ']';
        for(string::size_type iter = 0; iter < s.length(); iter++)
        {
            if(s[iter] == '(' || s[iter] == '{' || s[iter] == '[')
            {
                sc.push(s[iter]);
            }
            else if(sc.empty() || s[iter] != mc[sc.top()])
            {
                return false;
            }
            else
            {
                sc.pop();
            }
        }
        return sc.empty();

    }
};
