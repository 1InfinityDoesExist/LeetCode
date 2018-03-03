class Solution {
public:
    int maxArea(vector<int>& height) {
        int water (0);
        int iter = 0;
        int jter = height.size()-1;
        while(iter < jter)
        {
            int h = min(height[iter], height[jter]);
            water = max(water, (jter-iter)*h);
            while(height[iter] <= h && iter < jter)
            {
                iter++;
            }
            while(height[jter] <= h && iter < jter)
            {
                jter--;
            }
        }
        return water;

    }
};
