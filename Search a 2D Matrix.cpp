class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(matrix.size() == 0)
        {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = (row * col) -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;;
            int mid_val = matrix[mid/col][mid%col];
            if( mid_val == target)
            {
                return true;
            }
            else if(mid_val < target)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return false;
    }
};
