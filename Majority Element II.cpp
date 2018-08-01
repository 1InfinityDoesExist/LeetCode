class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mp;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        {
            mp[*iter]++;
            if(mp[*iter] > nums.size()/3)
            {
                if(find(ans.begin(), ans.end(), *iter) != ans.end())
                {
                    continue;
                }
                ans.push_back(*iter);
            }
        }
        return ans;
    }
};
