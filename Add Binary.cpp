class Solution {
public:
    string addBinary(string a, string b) {
        string str = "";
        int c = 0;
        int iter = a.size()-1;
        int jter = b.size()-1;
        while(iter >= 0 || jter >= 0 || c == 1)
        {
            c += iter >= 0 ? a[iter--] - '0' : 0;
            c += jter >= 0 ? b[jter--] - '0' : 0;
            str = char(c%2 + '0') + str;
            c /= 2;
        }
        return str;
    }
};
