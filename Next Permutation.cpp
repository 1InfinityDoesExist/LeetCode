class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty())
        {
            return;
        }
        int iter;
        for(iter = nums.size()-2; iter >= 0; iter--)
        {
            if(nums[iter] < nums[iter+1])
            {
                break;
            }
        }
        reverse(nums.begin()+iter+1, nums.end());
        if(iter == -1)
        {
            return;
        }
        else
        {
            vector<int>::iterator ite = upper_bound((nums.begin()+iter+1) , nums.end(), nums[iter]);
            swap(nums[iter], *ite);
        }



    }
};
