class Solution {
public:
    void swap(int *a, int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        map<int, int> mp;
        for(int iter = 0; iter < nums.size(); iter++)
        {
            mp[nums[iter]]++;
        }
        for(map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
        {
            if(iter->second == 2)
            {
                res.push_back(iter->first);
            }
        }


        for(int iter = 0; iter < nums.size(); iter++)
        {
            if(nums[iter] > 0 && nums[iter] <= nums.size())
            {
                int pos = nums[iter]-1;
                if(nums[pos] != nums[iter])
                {
                    swap(&nums[pos], &nums[iter]);
                    iter--;
                }
            }
        }
        for(int iter = 0; iter < nums.size(); iter++)
        {
            if(nums[iter] != iter+1)
            {
                res.push_back(iter+1);
                return res;
            }
        }
        res.push_back(nums.size()+1);
        return res;
    }
};
