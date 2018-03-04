class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
        {
            return 0;
        }
        if(x == 1)
        {
            return 1;
        }

        int start = 1;
        int end = x;
        int sqrt;
        while(start <= end)
        {
            int mid = (start+end)/2;
            if(mid <= x/mid)
            {
                start = mid+1;
                sqrt = mid;
            }
            else
            {
                end = mid-1;
            }
        }
        return sqrt;

    }
};
