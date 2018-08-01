
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> mp;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        {
            mp[*iter]++;
        }
        vector<int> ans;
        for(map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
        {
            if(mp[iter->first] == 2)
            {
                ans.push_back(iter->first);
            }
        }
        return ans;
    }
};
