class Solution {
  int min_ope(int n,int curr, int prev)
  {
    if (n == curr)
      return 0;
    
    if (n < curr)
      return 10000007;
    
    if (prev == curr)
      return 1 + min_ope(n,2*curr,curr);
    
    else
      return 1+ min(min_ope(n,curr+prev,prev),min_ope(n,curr,curr));
  }
public:
    int minSteps(int n) {
        return (n == 1) ? 0 : 1 + min_ope(n,1,1);
    }
};