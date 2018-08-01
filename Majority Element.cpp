class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        map<int, int> mp;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        {
            mp[*iter]++;
        }
        for(map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
        {
            if(mp[iter->first] > nums.size()/2)
            {
                return iter->first;
            }
        }
    }
};
