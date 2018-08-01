class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        vector<int> v;
        for(int iter = 0; iter < matrix.size(); iter++)
        {
            for(int jter = 0; jter < matrix[iter].size(); jter++)
            {
                v.push_back(matrix[iter][jter]);
            }
        }
        sort(v.begin(), v.end());
        return v[k-1];
    }
};
