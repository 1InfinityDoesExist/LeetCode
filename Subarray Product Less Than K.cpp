class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int count (0);
        int res = 1;
        for(int start = 0, end = 0; end < nums.size(); end++)
        {
           res = res * nums[end];
            while(start < end && res >= k)
            {
                res /= nums[start++];
            }
            if(res < k)
            {
                int data = end-start+1;
                count += data;
            }
        }
        return count;
    }
};
