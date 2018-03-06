class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cum = 0;
        map<int, int> mp;
        mp[0]++;
        int cnt (0);
        for(int iter = 0; iter < nums.size(); iter++)
        {
            cum = cum + nums[iter];
            cnt = cnt + mp[cum-k];
            mp[cum]++;
        }

        return cnt;
    }
};
