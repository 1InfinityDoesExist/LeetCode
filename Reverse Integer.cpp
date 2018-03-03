
class Solution {
public:
    void swap(char *a, char *b)
    {
        char temp = *a;
        *a = *b;
        *b = temp;
    }
    int reverse(int x)
    {
        bool neg = false;
        if(x < 0)
        {
            neg = true;
        }
        x = abs(x);
        int reverseInt (0);

        string cp = to_string(x);

        for(int iter = 0; iter < cp.length()/2; iter++)
        {
            swap(&cp[iter], &cp[cp.length()-iter-1]);
        }
         cp.erase(0, cp.find_first_not_of('0'));
      //  cout << cp << endl;
        while(x != 0)
        {
            reverseInt = (reverseInt * 10) + x%10;
            x /= 10;
        }
        string str = to_string(reverseInt);
      //  cout << str << endl;
        if(str != cp)
        {
            return 0;
        }
        str.erase(0, str.find_first_not_of('0'));
        if( str.length() == 0)
        {
            return 0;
        }

        int k = stoi(str);
        if(neg)
        {
            k = k * -1;
        }

        return k;



    }
};
