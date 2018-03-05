class Solution {
public:
    static bool comp(pair<char ,int> &A, pair<char, int> &B)
    {
        if(A.second == B.second)
        {
            return A.first < B.first;
        }
        return A.second > B.second;
    }
    string frequencySort(string s) {
        map<char, int> mp;
        for(string::size_type iter = 0; iter < s.length(); iter++)
        {
            mp[s[iter]]++;
        }
        vector<pair<char, int> > vp;
        for(map<char, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
        {
            vp.push_back(make_pair(iter->first, iter->second));
        }
        sort(vp.begin(), vp.end(), comp);
        s = "";
        for(vector<pair<char, int>>::iterator iter = vp.begin(); iter != vp.end(); iter++)
        {
            pair<char, int> p = *iter;
            int freq = p.second;
            while(freq--)
            {
                s += p.first;
            }
        }
        return s;
    }
};
