class Solution {
  vector<vector<long long>> dp;
  vector<vector<long long>> prices_map;
  
  long long min_cost(int m, int n)
  {
    long long cost = prices_map[m][n];
    
    if (dp[m][n] != -1)
      return dp[m][n];
    
    for (int i = 1; i < m; i++)
      cost = max(cost,min_cost(i,n) + min_cost(m-i,n));
    
    for (int i = 1; i < n; i++)
      cost = max(cost,min_cost(m,i) + min_cost(m,n-i));
    
    return dp[m][n] = cost;
  }
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        
      dp = vector<vector<long long>> (m+1,vector<long long>(n+1,-1));
      prices_map = vector<vector<long long>> (m+1,vector<long long>(n+1,0));
     
      for (int i = 0; i < prices.size(); i++)
        prices_map[prices[i][0]][prices[i][1]] = prices[i][2];
      
      return min_cost(m,n);
    }
};