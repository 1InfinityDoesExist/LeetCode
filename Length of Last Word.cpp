class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0)
        {
            return 0;
        }
        if(s.length() == 1 && s[0] == ' ')
        {
            return 0;
        }
        if(s.length() == 1)
        {
            return 1;
        }

        vector<string> st;
        string str = "";
        for(int iter = 0; iter < s.length(); iter++)
        {

            if(s[iter] == ' ')
            {
                if(str.length() == 0)
                {
                    continue;
                }
                else
                {
                    st.push_back(str);
                    str = "";
                }
            }

            else
            {
                str = str + s[iter];
                if(iter == s.length()-1)
                {
                    st.push_back(str);
                }

            }
        }
        if(st.size() == 0)
        {
            return 0;
        }
        string ss = st[st.size()-1];
        return ss.length();
    }
};
