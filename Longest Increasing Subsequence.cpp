class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int *temp = (int *)malloc(sizeof(int) * n);

        for(int iter = 0; iter < n; iter++)
        {
            temp[iter] = 1;
        }

        for(int iter = 1; iter < n; iter++)
        {
            for(int jter = 0; jter < iter; jter++)
            {
                if(nums[iter] > nums[jter] && temp[iter] < temp[jter]+1)
                {
                    temp[iter] = temp[jter]+1;
                }
            }
        }
        int mx (0);
        for(int iter = 0; iter < n; iter++)
        {
            if(mx < temp[iter])
            {
                mx = temp[iter];
            }
        }
        return mx;
    }
};
