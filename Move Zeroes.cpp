class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        int new_len = nums.size();
        int diff = len - new_len;
        while(diff--)
        {
            nums.push_back(0);
        }
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        {
            cout << *iter << " ";
        }
    }
};
