class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
        {
            return 0;
        }

        const int m = matrix.size();
        const int n = matrix[0].size();
        int left[n];
        int right[n];
        int height[n];
     /*   memset(left, 0, sizeof(left));
        memset(right, n, sizeof(right));
        memset(height, 0, sizeof(height));*/
            fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);


        int maxA (0);
        for(int iter = 0; iter < m; iter++)
        {
            int cur_left = 0;
            int cur_right = n;
            for(int jter = 0; jter < n; jter++)
            {
                if(matrix[iter][jter] == '1')
                {
                    height[jter]++;
                }
                else
                {
                    height[jter] = 0;
                }
            }

            for(int jter = 0; jter < n; jter++)
            {
                if(matrix[iter][jter] == '1')
                {
                    left[jter] = max(left[jter], cur_left);
                }
                else
                {
                    left[jter] = 0;
                    cur_left = jter+1;
                }
            }

            for(int jter = n-1; jter >= 0; jter--)
            {
                if(matrix[iter][jter] == '1')
                {
                    right[jter] = min(right[jter], cur_right);
                }
                else
                {
                    right[jter] = n;
                    cur_right = jter;
                }
            }

            for(int jter = 0; jter < n; jter++)
            {
                maxA = max(maxA, (right[jter]-left[jter]) * height[jter]);
            }
        }
        return maxA;

    }
};
