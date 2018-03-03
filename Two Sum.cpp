class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> m;
        for(int iter = 0; iter < nums.size(); iter++)
        {
            int required = target - nums[iter];
            if(m.find(required) != m.end())
            {
                ans.push_back(m[required]);
                ans.push_back(iter);
            }
            if(m.find(nums[iter]) == m.end())
            {
                m[nums[iter]] = iter;
            }
        }
        return ans;

    }
};
