/* https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/ */

/*
We don't need to find the exact the whole series for any n,
the left hand side series is the previous one and on the right hand inverse of the whole bits
we can solve with just this and through this the recursive solution comes up becasue this series will keep going on.
*/

class Solution {
public:
    
    char findKthBit(int n, int k) {
        if (n == 1 || k == 1)
        {
            return '0';
        }
        int mid  = (pow(2,n) +1 )/ 2 ;
        
        if (mid  == k)
        {
            return '1';
        }
        if ( k < mid )
        {
            return findKthBit(n-1,k);
        }
        if (findKthBit(n-1,mid - (k -mid)) == '1')
            return '0';
        return '1';
    }
};
