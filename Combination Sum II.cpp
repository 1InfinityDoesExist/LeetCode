class Solution {
public:

    void findCombination(vector<vector<int> > &res, int order, int target, vector<int> &local, vector<int> &num)
    {
        if(target == 0)
        {
            res.push_back(local);
            return;
        }
        else
        {
            for(int iter = order; iter < num.size(); iter++)
            {
                if(num[iter] > target)
                {
                    return;
                }
                if(iter && num[iter] == num[iter-1] && iter > order)
                {
                    continue;
                }
                local.push_back(num[iter]);
                findCombination(res, iter+1, target-num[iter], local, num);
                local.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        vector<int> local;
        findCombination(res, 0, target, local, candidates);
        return res;
    }
};
