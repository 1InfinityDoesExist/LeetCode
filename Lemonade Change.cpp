class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int five = 0;
        int ten = 0;
        if(bills[0] > 5)
        {
            return false;
        }
        for(int iter = 0; iter < bills.size(); iter++)
        {
            if(bills[iter] == 5)
            {
                five = five + 5;
            }
            else if(bills[iter] == 10)
            {
                if(five >= 5)
                {
                    ten = ten + 10;
                    five = five - 5;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(ten >= 10 && five >= 5 || five >= 15)
                {
                    if(ten >= 10)
                    {
                        ten = ten - 10;
                        five = five - 5;
                    }
                    else
                    {
                        five = five - 15;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
