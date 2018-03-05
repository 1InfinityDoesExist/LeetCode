class Solution {
public:
    static bool comp(pair<int, int> &A, pair<int, int> &B)
    {
        if(A.second == B.second)
        {
            return A.first < B.first;
        }
        return A.second > B.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> v;
        map<int, int> mp;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        {
            mp[*iter]++;
        }
        vector<pair<int, int> > vp;
        for(map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
        {
            vp.push_back(make_pair(iter->first, iter->second));
        }
        sort(vp.begin(), vp.end(), comp);

        for(int iter = 0; iter < k ;iter++)
        {
            pair<int, int> p = vp[iter];
            v.push_back(p.first);
        }
        return v;
    }
};
