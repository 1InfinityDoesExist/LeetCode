class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        for(int iter = 0; iter < nums.size(); iter++)
        {
            int target = -nums[iter];
            int front = iter+1;
            int back = nums.size()-1;
            while(front < back)
            {
                int sum = nums[front] + nums[back];
                if(sum < target)
                {
                    front++;
                }
                else if(sum > target)
                {
                    back--;
                }
                else
                {
                    vector<int> triplet(3,0);
                    triplet[0] = nums[iter];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);
                    while(front < back && nums[front] == triplet[1])
                    {
                        front++;
                    }
                    while(front < back && nums[back] == triplet[2])
                    {
                        back--;
                    }
                }
            }
            while(iter +1 < nums.size() && nums[iter+1] == nums[iter])
            {
                iter++;
            }
        }
        return res;

    }
};
