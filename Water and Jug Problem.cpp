class Solution {
public:
    int gcd(int a, int b)
    {
        if(b == 0)
        {
            return a;
        }
        return gcd(b, a%b);
    }
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || z <= (long long)x + y && z % gcd(x, y) == 0;
    }
};
