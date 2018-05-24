
int min(int x, int y)
{
    return x < y ? x : y;
}
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if(matrix.size() == 0)
        {
            return 0;
        }

        for(int iter = 0; iter < matrix.size(); iter++)
        {
            for(int jter = 0; jter < matrix[iter].size(); jter++)
            {
                matrix[iter][jter] = matrix[iter][jter] - '0';
            }
        }
        int row = matrix.size();
        int col = matrix[0].size();

        int S[row][col];
        int max_of_s, max_i, max_j;

        for(int iter = 0; iter < row; iter++)
        {
            S[iter][0] = matrix[iter][0];
        }
        for(int jter = 0; jter < col; jter++)
        {
            S[0][jter] = matrix[0][jter];
        }
        for(int iter = 1; iter < row; iter++)
        {
            for(int jter = 1; jter < col; jter++)
            {
                if(matrix[iter][jter] == 1)
                {
                    S[iter][jter] = min(min(S[iter-1][jter], S[iter][jter-1]), S[iter-1][jter-1]) + 1;
                }
                else
                {
                    S[iter][jter] = 0;
                }
            }
        }

        max_of_s = S[0][0];
        max_i = 0;
        max_j = 0;

        for(int iter = 0; iter < row; iter++)
        {
            for(int jter = 0; jter < col; jter++)
            {
                if(max_of_s < S[iter][jter])
                {
                    max_of_s = S[iter][jter];
                    max_i = iter;
                    max_j = jter;
                }
            }
        }

        int count (0);

        for(int iter = max_i; iter > max_i - max_of_s; iter--)
        {
            count++;
           /* for(int jter = max_j; jter > max_j - max_of_s; jter--)
            {
                cout << matrix[iter][jter] << " ";
            }
            cout << endl;*/
        }

        return count*count;
    }
};
