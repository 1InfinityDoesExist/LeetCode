class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        vector<int> A = nums;
       int low = 0;
   int high = A.size()-1;
   int mid (0);
   while(low < high)
   {
       mid = low + (high - low)/2;

       if(mid == low)
       {
           break;
       }
       if(A[mid] == A[mid+1])
       {
           if(mid%2 == 0)
           {
               low = mid +2;
           }
           else
           {
               high = mid;
           }
       }
       else if(A[mid] == A[mid-1])
       {
           if(mid%2 == 0)
           {
               high = mid -1;
           }
           else
           {
               low = mid+1;
           }
       }
   }
  return A[low] ;
 /* long long int ones (0);
  long long int twos (0);
  for(long long int iter = 0; iter < A.size(); iter++)
  {
      ones = (ones ^ A[iter]) & ~twos;
      twos = (twos ^ A[iter]) & ~ones;
  }
    return ones;*/
    }
};
