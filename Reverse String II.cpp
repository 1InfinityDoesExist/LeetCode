
class Solution {
public:
    string reverseStr(string s, int k) {
        for(string::size_type iter = 0; iter < s.length(); iter = iter +(2*k))
        {
            reverse(s.begin()+iter, min(s.begin()+iter+k, s.end()));
        }
        return s;
    }
};
