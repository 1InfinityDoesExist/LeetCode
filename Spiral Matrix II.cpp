class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        int m = n;
        int nn = n;
        vector<vector<int> > matrix;
        for(int iter = 0; iter < n ;iter++)
        {
            vector<int> temp;
            for(int jter = 0; jter < n; jter++)
            {
                temp.push_back(0);
            }
            matrix.push_back(temp);
        }
        int k = 0, l = 0;
        int i (1);
        while(k < m && l < nn)
        {
            for(int iter = l; iter < nn; iter++)
            {
                matrix[k][iter] = i++;;
            }
            k++;
            for(int iter = k; iter < m; iter++)
            {
                matrix[iter][nn-1] = i++;
            }
            nn--;
            if(k < m)
            {
                for(int iter = nn-1; iter >= l; iter--)
                {
                    matrix[m-1][iter] = i++;
                }
                m--;
            }
            if(l < nn)
            {
                for(int iter = m-1; iter >= k; iter--)
                {
                    matrix[iter][l] = i++;
                }
                l++;
            }
        }
        return matrix;
    }
};
