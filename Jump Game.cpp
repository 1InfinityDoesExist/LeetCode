
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size()-1;
        for(int iter = lastPos; iter >= 0; iter--)
        {
            if(iter + nums[iter] >= lastPos)
            {
                lastPos = iter;
            }
        }
        return lastPos == 0;
    }
};
