class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
       map<int, int> mp;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        {
            mp[*iter]++;
        }
        for(int iter = 1; iter <= nums.size(); iter++)
        {
            if(mp.find(iter) == mp.end())
            {
                ans.push_back(iter);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
