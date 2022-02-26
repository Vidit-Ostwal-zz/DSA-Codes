class Solution {
  int get_max(int n,vector<int>&dp)
  {
    if (n <= 2)
      return 1;
    
    if (dp[n] != -1)
      return dp[n];
    
    int maxi = INT_MIN;
    
    for (int i = 1; i < n; i++)
      maxi = max(maxi,max(i,get_max(i,dp))*max(n-i,get_max(n-i,dp)));
    
    return dp[n] = maxi;
  }
public:
    int integerBreak(int n) {
      vector<int> dp(n+1,-1);
        return get_max(n,dp);
    }
};