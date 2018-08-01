class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A)
    {

        int jter = A.size()-1;
        while(jter >= 0)
        {
            if(A[jter] <= A[jter-1])
            {
                jter--;
            }
            else
            {
                break;
            }
        }
        int iter = 0;
        while(iter <= jter)
        {
            if(iter == jter)
            {
                return iter;
            }
            if(A[iter] > A[iter+1])
            {
                return iter;
            }
            iter++;
        }
        return iter;
    }
};
