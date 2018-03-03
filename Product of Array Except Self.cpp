class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> v;
        v.push_back(1);
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        {
            v.push_back(v.back() * (*iter));
        }
        int k (1);
        for(int iter = 0; iter < nums.size(); iter++)
        {
            v[nums.size()-iter-1] = v[nums.size()-iter-1] * k;
            k = k * nums[nums.size()-iter-1];
        }
        v.pop_back();
        return v;
    }
};
