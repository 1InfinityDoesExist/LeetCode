void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int iter = 0; iter < nums.size(); iter++)
        {
            if(nums[iter] >= 0 && nums[iter] < nums.size())
            {
                int pos = nums[iter];
                if(nums[pos] != nums[iter])
                {
                    swap(nums[pos], nums[iter]);
                    iter--;
                }
            }
        }
        for(int iter = 0; iter < nums.size(); iter++)
        {
            if(nums[iter] != iter)
            {
                return iter;
            }
        }
        return nums.size();

    }
};
