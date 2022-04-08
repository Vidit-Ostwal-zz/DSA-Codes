class Solution {
  vector<int> dp;
  int min_re(int n)
  {
    if (n < 0)
      return 0;
    
    if (dp[n] != -1)
      return dp[n];
    
    
    
    int s = sqrt(n);
    if (s*s == n)
      return dp[n] = 1;
    
    int mini = INT_MAX;
    for (int i = 1; i <= s; i++)
      mini = min(mini,1+ min_re(n-i*i));
    
    return dp[n] = mini;
  }
public:
    int numSquares(int n) {
      dp = vector<int>(n+1,-1);
        return min_re(n);
    }
};