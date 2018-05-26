bool comp(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), comp);

        int *temp = (int *)malloc(sizeof(int) * n);
        for(int iter = 0; iter < n ;iter++)
        {
            temp[iter] = 1;
        }
        for(int iter = 1; iter < n; iter++)
        {
            for(int jter = 0; jter < iter; jter++)
            {
                if(pairs[iter][0] > pairs[jter][1] && temp[iter] < temp[jter]+1)
                {
                    temp[iter] = temp[jter] +1;
                }
            }
        }
        int mx (0);
        for(int iter = 0; iter < n ;iter++)
        {
            if(mx < temp[iter])
            {
                mx = temp[iter];
            }
        }
        free(temp);
        return mx;
    }
};
