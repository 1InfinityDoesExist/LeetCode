	vector<string> toString(const vector<int> &ans)
    {
        int n = ans.size();
        vector<string> str(n);
        for(int iter = 0; iter < ans.size(); iter++)
        {
            str[iter] = string(n,'.');
            str[iter][ans[iter]] = 'Q';
        }
        return str;
    }

    bool isSafe(const vector<int> &ans, int iter, int jter)
    {
        for(int kter = 0; kter < iter; kter++)
        {
           if(jter == ans[kter] || iter+jter == kter + ans[kter] || iter-jter == kter - ans[kter])
            {
                return false;
            }
        }
        return true;
    }


    void solve_NQueen(int row, vector<int> &ans, vector<vector<string> > &str)
    {
        int n = ans.size();
        if(row == n)
        {
            str.push_back(toString(ans));
            return;
        }

        for(int jter = 0; jter < n; jter++)
        {
            if(isSafe(ans, row, jter))
            {
                ans[row] = jter;
                solve_NQueen(row+1, ans, str);
            }
        }
    }


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string> > vstr;
        vector<int> ans(n);
        solve_NQueen(0,ans, vstr);
        return vstr;
    }


};



