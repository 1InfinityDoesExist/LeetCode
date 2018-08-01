class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
    {
        vector<vector<int> > res;
        for(int iter = 0; iter < A.size(); iter++)
        {
            vector<int> ans = A[iter];
            reverse(ans.begin(), ans.end());
            for(int jter = 0; jter < ans.size(); jter++)
            {
                if(ans[jter] == 0)
                {
                    ans[jter] = 1;
                }
                else
                {
                    ans[jter] = 1;
                    ans[jter] = 0;
                }
            }
            res.push_back(ans);

        }
        return res;
    }
};
