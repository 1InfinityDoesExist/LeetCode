class Solution {
public:

    int min(int x, int y)
    {
        return x < y ? x : y;
    }
    int max(int x, int y)
    {
        return x > y ? x : y;
    }
    int trap(vector<int>& height)
    {
        if(height.size() < 0)
        {
            return 0;
        }
        int len = height.size();
        int water = 0;
        int *left = new int[len];
        int *right = new int[len];

        left[0] = 0;
        for(int iter = 1; iter < len; iter++)
        {
            left[iter] = max(left[iter-1],height[iter-1]);
        }

        right[len-1] = 0;
        for(int jter = len-2; jter >= 0; jter--)
        {
            right[jter] = max(right[jter+1], height[jter+1]);
        }

        for(int iter = 0; iter < len-1; iter++)
        {
            if( min(left[iter], right[iter]) - height[iter] > 0)
            {
                water = water + min(left[iter], right[iter]) - height[iter];
            }
        }
        return water;

    }
};
