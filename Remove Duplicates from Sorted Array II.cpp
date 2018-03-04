class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count (0);
        for(int iter = 2; iter < n; iter++)
        {
            if(nums[iter] == nums[iter-2-count])
            {
                count++;
            }
            else
            {
                nums[iter-count] = nums[iter];
            }
        }
        return n-count;
    }
};
