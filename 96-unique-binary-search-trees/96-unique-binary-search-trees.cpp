class Solution {
  int count(int n,vector<int> &dp)
  {
    if (n == 0)
      return 1;
    
    if (n < 3)
      return n;
    
    if (dp[n] != -1)
      return dp[n];
    int answer = 0;
    
    for (int i = 0; i < n; i++)
    {answer += count(i,dp) * count(n-i-1,dp);}
    
    return dp[n] = answer;
  }
public:
    int numTrees(int n) {
      if (n == 0 ) return 0;
      vector<int>dp(n+1,-1);
        return count(n,dp);
    }
};