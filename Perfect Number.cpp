class Solution {
public:
    bool checkPerfectNumber(int num) {
        long long sum (1);
        for(int iter = 2; iter <= sqrt(num); iter++)
        {
            if(num%iter == 0)
            {
                sum = sum + iter + (num/iter);
            }
        }
        if(sum == num && num != 1)
        {
            return true;
        }
        return false;

    }
};
