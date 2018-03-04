class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        vector<int> res;
        int carry = 0;
        int add = 1;
        for(int iter = digits.size()-1; iter >= 0; iter--)
        {
            if(digits[iter] == 0)
            {
                res.push_back(digits[iter] + add + carry);
                carry = 0;
                add = 0;
            }
            else
            {
                int sumx = digits[iter] + add + carry;
                int rem = sumx%10;
                res.push_back(rem);
                if(rem == 0)
                {
                    carry = 1;
                    add = 0;
                }
                else
                {
                    carry = 0;
                    add = 0;
                }
            }
        }

        if(carry == 1)
        {
            res.push_back(carry);
            reverse(res.begin(), res.end());
            return res;
        }
        reverse(res.begin(), res.end());
        return res;
    }

};
