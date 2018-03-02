
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > subset;
        vector<int> empty;
        subset.push_back(empty);
        map<vector<int> , int > mp;
        for(int iter = 0; iter < nums.size(); iter++)
        {
            vector<vector<int> > cp = subset;
            for(int jter = 0; jter < cp.size(); jter++)
            {
                cp[jter].push_back(nums[iter]);
            }
            for(int jter = 0; jter < cp.size(); jter++)
            {
                vector<int> vi = cp[jter];
                sort(vi.begin(), vi.end());
                subset.push_back(vi);
            }
        }
        sort(subset.begin(), subset.end());
        subset.erase(unique(subset.begin(), subset.end()), subset.end());
        return subset;
    }
};
