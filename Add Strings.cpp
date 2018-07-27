class Solution {
public:
    int max(int x, int y)
    {
        return x > y ? x : y;
    }
    string addStrings(string num1, string num2)
    {
        int mx = max(num1.length(), num2.length());
        if(mx > num1.length())
        {
            num1 = string(mx-num1.length(), '0') + num1;
        }
        if(mx > num2.length())
        {
            num2 = string(mx-num2.length(), '0') + num2;
        }
        string final(mx+1, '0');
        string::const_reverse_iterator iter = num1.rbegin(), it = num1.rend();
        string::const_reverse_iterator jter = num2.rbegin();
        string::reverse_iterator fter = final.rbegin();

        int carry = 0;
        for(; iter != it; iter++, jter++, fter++)
        {
            char temp = (*iter - '0') + (*jter - '0') + carry;
            if(temp > 9)
            {
                carry = 1;
                temp = temp%10;
            }
            else
            {
                carry = 0;
            }
            *fter = temp + '0';
        }

            final[0] = carry + '0';
            size_t startpos = final.find_first_not_of('0');
            if(string::npos != startpos)
            {
                string ans = final.substr(startpos);
                return ans;
            }
            else
            {
                return "0";
            }


    }
};
