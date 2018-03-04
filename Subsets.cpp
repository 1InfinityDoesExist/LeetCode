class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > subset;
    vector<int> khali;
    subset.push_back(khali);

    for (int i = 0; i < nums.size(); i++)
    {
        vector< vector<int> > cp = subset;

        for (int j = 0; j < cp.size(); j++)
            cp[j].push_back(nums[i] );

        for (int j = 0; j < cp.size(); j++)
            subset.push_back( cp[j] );
    }
    sort(subset.begin(), subset.end());
    subset.erase(unique(subset.begin(), subset.end()), subset.end());
    return subset;

    }
};
