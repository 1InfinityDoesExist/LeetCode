class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
        {
            return false;
        }
        unsigned long long int x = pow(3, 22);
        if(x%n == 0)
        {
            return true;
        }
        return false;

    }
};
