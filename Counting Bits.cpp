class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num+1, 0);
        for(int iter = 1; iter <= num; iter++)
        {
            bits[iter] = bits[iter] + bits[iter & (iter-1)] + 1;
        }
        return bits;
    }
};
