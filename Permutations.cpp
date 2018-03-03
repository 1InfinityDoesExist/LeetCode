class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > vvi;
        sort(nums.begin(), nums.end());
        do
        {
            vvi.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return vvi;

    }
};
