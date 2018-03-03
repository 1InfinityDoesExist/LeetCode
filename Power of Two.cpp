class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0)
        {
            return false;
        }
        string str = "";
        while(n != 0)
        {
            str = ((n%2 == 0) ? "0" : "1") + str;
            n /= 2;
        }
        bitset<120>foo(str);
        if(foo.count() == 1)
        {
            return true;
        }
        return false;

    }
};
