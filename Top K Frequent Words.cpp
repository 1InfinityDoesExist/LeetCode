class Solution {
public:
    static bool comp(pair<string, int> &A, pair<string, int> &B)
    {
        if(A.second == B.second)
        {
            return A.first < B.first;
        }
        return A.second > B.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        vector<string> v;
        map<string, int> mp;
        for(vector<string>::iterator iter = words.begin(); iter != words.end(); iter++)
        {
            mp[*iter]++;
        }
        vector<pair<string, int> > vp;
        for(map<string, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
        {
            vp.push_back(make_pair(iter->first, iter->second));
        }
        sort(vp.begin(), vp.end(), comp);
        for(int iter = 0; iter < k; iter++)
        {
            pair<string, int> p = vp[iter];
            v.push_back(p.first);
        }
        return v;
    }
};
