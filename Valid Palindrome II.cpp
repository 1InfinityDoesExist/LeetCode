class Solution {
public:
    bool isPalin(string::iterator low, string::iterator high)
    {
        while(low < high)
        {
            if(*low != *high)
            {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int low = 0;
        int high = s.length()-1;
        while(low < high)
        {
            if(s[low] == s[high])
            {
                low++;
                high--;
            }
            else
            {
                if(isPalin(s.begin()+low+1, s.begin()+high))
                {
                    return true;
                }
                if(isPalin(s.begin()+low, s.begin()+high-1))
                {
                    return true;
                }
                return false;
            }
        }
        return true;
    }
};
