class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
         int count (0);
        for(int iter = 0; iter < A.size(); )
        {
            int left = A.size();
            int right = -1;
            for(int jter = iter; jter < A.size(); jter++)
            {
                left = min(left, A[jter]);
                right = max(right, A[jter]);
                if(left == iter && right == jter)
                {
                    iter = jter+1;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
