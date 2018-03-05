class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        if(matrix.size() == 0)
        {
            return 0;
        }
       for(int iter = 1; iter < matrix.size(); iter++)
       {
           for(int jter = 1; jter < matrix[iter].size(); jter++)
           {
               if(matrix[iter][jter] != matrix[iter-1][jter-1])
               {
                   return false;
               }
           }
       }
        return true;
    }
};
