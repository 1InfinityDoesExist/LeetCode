class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int longest (0);
        stack<int> st;
        for(int iter = 0; iter < n; iter++)
        {
            if(s[iter] == '(')
            {
                st.push(iter);
            }
            else
            {
                if(!st.empty())
                {
                    if(s[st.top()] == '(')
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(iter);
                    }
                }
                else
                {
                    st.push(iter);
                }
            }
        }
        if(st.empty())
        {
            longest = n;
        }
        else
        {
            int a = n; int b = 0;
            while(!st.empty())
            {
                b = st.top();
                st.pop();
                longest = max(longest, a-b-1);
                a = b;
            }
            longest = max(longest, a);
        }
        return longest;
    }
};
