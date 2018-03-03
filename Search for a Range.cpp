class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(count(nums.begin(), nums.end(), target) == 0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else
        {
            int cnt = count(nums.begin(), nums.end(), target);

            for(int iter = 0; iter < nums.size(); iter++)
            {
                if(nums[iter] == target)
                {
                    ans.push_back(iter);
                    ans.push_back(iter+cnt-1);
                    break;
                }
            }
        }
        return ans;


    }
};
