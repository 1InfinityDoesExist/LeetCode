class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A)
    {
        vector<vector<int> > ans;
        int jter = 0;
        int col = A[0].size();
        while(jter < col)
        {
            vector<int> B;
            int iter = 0;
            while(iter < A.size())
            {
               B.push_back(A[iter][jter]);
                iter++;
            }
            ans.push_back(B);
            jter++;
        }
        return ans;
    }
};
