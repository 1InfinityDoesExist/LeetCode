class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for(int iter = 0; iter < n/2; iter++)
        {
            for(int jter = iter; jter < n-1-iter; jter++)
            {
                int temp = matrix[iter][jter];
                matrix[iter][jter] = matrix[n-1-jter][iter];
                matrix[n-1-jter][iter] = matrix[n-1-iter][n-1-jter];
                matrix[n-1-iter][n-1-jter] = matrix[jter][n-1-iter];
                matrix[jter][n-1-iter] = temp;
            }
        }
    }
};
