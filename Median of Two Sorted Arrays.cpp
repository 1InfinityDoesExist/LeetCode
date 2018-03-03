class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(res));
        int len = res.size();
        if(res.size()%2 != 0)
        {
            return (double)res[len/2];
        }
        return (double)(res[len/2] + res[(len-1)/2])/2.0;

    }
};
