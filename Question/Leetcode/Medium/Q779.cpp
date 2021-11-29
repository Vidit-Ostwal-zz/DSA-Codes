/* https://leetcode.com/problems/k-th-symbol-in-grammar/ */


/*
We don't need to find the exact the whole series for any n,
the left hand side series is the previous one and on the right hand inverse of the whole bits
we can solve with just this and through this the recursive solution comes up becasue this series will keep going on.
*/

class Solution {
public:

    int kthGrammar(int n, int k) {
        if (n == 1 || k == 1 )
        {
            return 0;
        }
        
        int mid  = pow(2,n-2);
        if (k <= mid)
        {
            return kthGrammar(n-1,k);
        }
        return kthGrammar(n-1,k-mid);
    }
};
