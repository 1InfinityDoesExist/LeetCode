class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ct = count(nums.begin(), nums.end(), 0);

        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        while(ct--)
        {
            nums.push_back(0);
        }
        return;

    }
};
