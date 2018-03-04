class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        if(row == 0 || col == 0)
        {
            return;
        }
        bool hasRowZero = false;
        bool hasColumnZero = false;
        for( int iter = 0; iter < matrix.size(); iter++)
        {
            if(matrix[iter][0] == 0)
            {
                hasColumnZero = true;
            }
        }
        for(int jter = 0; jter < matrix[0].size(); jter++)
        {
            if(matrix[0][jter] == 0)
            {
                hasRowZero = true;
            }
        }

        for(int iter = 1; iter < matrix.size(); iter++)
        {
            for(int jter = 1; jter < matrix[0].size(); jter++)
            {
                if(matrix[iter][jter] == 0)
                {
                    matrix[0][jter] = 0;
                    matrix[iter][0] = 0;
                }
            }
        }

        for(int iter = 1; iter < col; iter++ )
        {
            if(matrix[0][iter] == 0)
            {
                for(int jter = 1; jter < row; jter++)
                {
                    matrix[jter][iter] = 0;
                }
            }
        }

        for(int iter = 1; iter < row; iter++)
        {
            if(matrix[iter][0] == 0)
            {
                for(int jter = 1; jter < col; jter++)
                {
                    matrix[iter][jter] = 0;
                }
            }
        }

        if(hasRowZero)
        {
            for(int iter = 0; iter < col; iter++)
            {
                matrix[0][iter] = 0;
            }
        }
         if(hasColumnZero)
        {
            for(int iter = 0; iter < row; iter++)
            {
                matrix[iter][0] = 0;
            }
        }

    }
};
