class Solution {
public:
    string countAndSay(int n) {
        if(n == 0)
        {
            return " ";
        }
        string res = "1";
        while(--n)
        {
            string cur = "";
            for(int iter = 0; iter < res.length(); iter++)
            {
                int count = 1;
                while((iter+1 < res.length()) && res[iter] == res[iter+1])
                {
                    count++;
                    iter++;
                }
                cur = cur + to_string(count) + res[iter];
            }
            res = cur;
        }
        return res;

    }
};
