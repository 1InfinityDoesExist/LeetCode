class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> res;
        if(matrix.size() == 0)
        {
            return res;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        int k = 0, l = 0;

        while(k < m && l < n)
        {
            for(int iter = l; iter < n; iter++)
            {
                res.push_back(matrix[k][iter]);
            }
            k++;
            for(int iter = k; iter < m; iter++)
            {
                res.push_back(matrix[iter][n-1]);
            }
            n--;
            if(k < m)
            {
                for(int iter = n-1; iter >= l; iter--)
                {
                    res.push_back(matrix[m-1][iter]);
                }
                m--;
            }
            if(l < n)
            {
                for(int iter = m-1; iter >= k; iter--)
                {
                    res.push_back(matrix[iter][l]);
                }
                l++;
            }
        }
        return res;
    }
};
