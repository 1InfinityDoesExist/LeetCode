class Solution {
public:

    vector<long long int> prime;
    void primeCalculator()
    {
        vector<int> dp(10000, 0);
     //   memset(dp, 0, sizeof(dp));
        for(int iter = 2; iter < 1000; iter++)
        {
            if(dp[iter] == 0)
            {
                prime.push_back(iter);
                for(int jter = iter*2; jter < 1000; jter = jter+iter)
                {
                    dp[jter] = 1;
                }
            }
        }
    }


    int countPrimeSetBits(int L, int R)
    {
        primeCalculator();
        int count (0);
        for(int iter = L; iter <= R; iter++)
        {
            string str = "";
            int n = iter;
            while(n != 0)
            {
                str = ((n%2 == 0) ? "0" : "1") + str;
                n /= 2;
            }

            bitset<120>foo(str);
            if(find(prime.begin(), prime.end(), foo.count()) != prime.end())
            {
                count++;
            }
        }
        return count;
    }
};
