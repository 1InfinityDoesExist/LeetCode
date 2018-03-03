class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      for(int iter = 0; iter < nums.size(); iter++)
      {
          if(nums[iter] > 0 && nums[iter] <= nums.size())
          {
              int pos = nums[iter]-1;
              if(nums[pos] != nums[iter])
              {
                  swap(nums[pos], nums[iter]);
                  iter--;
              }
          }
      }
        for(int iter = 0; iter < nums.size(); iter++)
        {
            if(nums[iter] != iter+1)
            {
                return iter+1;
            }
        }
        return nums.size()+1;
    }
};
