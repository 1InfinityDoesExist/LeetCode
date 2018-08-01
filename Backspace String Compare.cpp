class Solution {
public:
    string solve(string str)
    {
        string ans = "";
        stack<char> s;
        for(string::size_type iter = 0; iter < str.length(); iter++)
        {
            if(str[iter] == '#')
            {
                if(!s.empty())
                {
                    s.pop();
                }
                else
                {
                    continue;
                }
            }
            else
            {
                s.push(str[iter]);
            }
        }
        while(!s.empty())
        {
            ans = s.top() + ans;
            s.pop();
        }
        return ans;
    }
    bool backspaceCompare(string S, string T)
    {
        string new_s = solve(S);
        string new_t = solve(T);
        if(new_s == new_t)
        {
            return true;
        }
        return false;
    }
};
