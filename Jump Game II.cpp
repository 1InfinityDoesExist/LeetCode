class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums[0] == 0)
        {
            return 0;
        }
        int start = 0;
        int end = 0;
        int steps = 0;
        int lastPos = nums.size()-1;
        while(end < lastPos)
        {
            steps++;
            int maxEnd = end+1;
            for(int iter = start; iter <= end; iter++)
            {
                if(iter + nums[iter] >= lastPos)
                {
                    return steps;
                }
                maxEnd = max(maxEnd, iter+nums[iter]);
            }
            start = end+1;
            end = maxEnd;
         /*  if(nums[end] == 0)
            {
                return 0;
            }*/
        }
        return steps;

    }
};
