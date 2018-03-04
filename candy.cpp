class Solution {
public:
    int max(int x, int y)
    {
        return x > y ? x : y;
    }
    int candy(vector<int>& ratings)
    {
        vector<int> left(ratings.size(), 1);

        vector<int> right(ratings.size(), 1);

        for(int iter = 1; iter < ratings.size(); iter++)
        {
            if(ratings[iter] > ratings[iter-1])
            {
                left[iter] = left[iter-1] +1;
            }
        }
        for(int iter = ratings.size()-2; iter >= 0; iter--)
        {
            if(ratings[iter] > ratings[iter+1])
            {
                right[iter] = right[iter+1] + 1;
            }
        }
        int ans (0);
        for(int iter = 0; iter < ratings.size(); iter++)
        {
            ans += max(left[iter], right[iter]);
        }
        return ans;
    }
};
