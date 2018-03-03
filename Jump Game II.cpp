class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = 0;
        int steps = 0;

        while(end < n-1)
        {
            steps++;
            int maxend = end+1;
            for(int iter = start; iter <= end; iter++)
            {
                if(iter+nums[iter] >= n-1)
                {
                    return steps;
                }
                maxend = max(maxend, iter+nums[iter]);
            }
            start = end+1;
            end = maxend;
          /*  if(nums[end] == 0)
            {
                return -1;
            }*/
        }
        return steps;

    }


};
