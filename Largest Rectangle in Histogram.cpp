class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> s;
        int maxArea = 0;
        int newArea;
        int iter = 0;
        while(iter < heights.size())
        {
            if(s.empty() || heights[s.top()] <= heights[iter])
            {
                s.push(iter++);
            }
            else
            {
                int ts = s.top();
                s.pop();
                newArea = heights[ts] * (s.empty() ? iter : iter-s.top()-1);
                if(maxArea < newArea)
                {
                    maxArea = newArea;
                }
            }
        }
        while(!s.empty())
        {
            int ts = s.top();
            s.pop();
            newArea = heights[ts] * (s.empty() ? iter : iter - s.top()-1);
            if(maxArea < newArea)
            {
                maxArea = newArea;
            }
        }
        return maxArea;
    }
};
