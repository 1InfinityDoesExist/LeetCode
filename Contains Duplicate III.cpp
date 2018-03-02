class Solution {
public:
    static bool comp(pair<int, int> A, pair<int, int> B)
    {
        return A.first < B.first;
    }
    bool search(vector<pair<int, int> > A, int k, int t)
    {
        int iter = 0;
        while(iter < A.size())
        {
            int jter = iter +1;
            while(jter < A.size())
            {
                if((abs(long(A[jter].first) - long(A[iter].first)) <= t) && (abs(long(A[jter].second) - long(A[iter].second)) <= k))
                {
                     return true;
                }
                else
                {
                    if(abs(long(A[jter].first - A[iter].first)) > t)
                    {
                        break;
                    }
                    else
                    {
                        jter++;
                    }
                }
            }
            iter++;
        }
        return false;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        if(nums.size() == 0)
        {
            return false;
        }
        vector<pair<int, int> > vp;
        int i = 0;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        {
            vp.push_back(make_pair(*iter, i));
            i++;
        }
        sort(vp.begin(), vp.end(), comp);

        return search(vp, k, t);
    }
};







