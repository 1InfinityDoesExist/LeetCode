class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator iter = find(nums.begin(), nums.end(), target);
        if(iter != nums.end())
        {
            return (iter - nums.begin());
        }
        else
        {
            for(int iter = 0; iter < nums.size(); iter++)
            {
                if(nums[iter] >= target)
                {
                    return iter;
                }
            }
        }
        return nums.size();
    }
};
