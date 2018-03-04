class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size()-1;
        for(int iter = nums.size()-1; iter >= 0; iter--)
        {
            if(nums[iter] + iter >= lastPos)
            {
                lastPos = iter;
            }
        }
        return lastPos == 0;

    }
};
