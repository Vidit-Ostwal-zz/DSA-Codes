class Solution {
  int recursive_solution(int n, int egg,vector<int>&dp)
  {
    if (egg == 1)
      return n;
    
    if (n  <= 1)
      return n;
    
    if (dp[n] != -1) return dp[n];
    
    int answer = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
      int temp = INT_MAX;
      temp = 1 + max(recursive_solution(i-1,egg-1,dp),recursive_solution(n-i,egg,dp));
      answer = min(answer,temp);
    }
    return dp[n] = answer;  
  }
public:
    int twoEggDrop(int n) {
      vector<int> dp(n+1,-1);
        return recursive_solution(n, 2,dp);
    }
};