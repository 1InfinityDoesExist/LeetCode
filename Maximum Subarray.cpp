class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int max_so_far (INT_MIN);
        int max_ending_here (0);
        for(int iter = 0; iter < nums.size(); iter++)
        {
            max_ending_here = max_ending_here + nums[iter];
            max_so_far = max(max_ending_here, max_so_far);
            if(max_ending_here < 0)
            {
                max_ending_here = 0;
            }
        }
        return max_so_far;
    }
};
