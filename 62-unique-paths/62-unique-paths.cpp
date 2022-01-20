class Solution {
public:
  int number_of_path_memo(int m, int n,vector<vector<int>> &dp)
  {
      if (m == 0 && n == 0)
      return 1;
      
      if (dp[m][n] != -1)
      {
          return dp[m][n];
      }
      int left = 0;
      int up = 0;
      
      if (m > 0)
      up = number_of_path_memo(m-1,n,dp);
      
      if (n > 0)
      left = number_of_path_memo(m,n-1,dp);
      
      return dp[m][n] = (left+up);
  }
  
  int number_of_path_tabu(int m, int n)
  {
      vector<vector<int>> dp (m+1,vector<int>(n+1,-1));
      
    for (int i = 0; i <= m; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        if (i == 0 || j == 0)
          dp[i][j] = 1;
        
        else
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
    return dp[m][n];
  }
  
  
    int uniquePaths(int m, int n) {
        
        return number_of_path_tabu(m-1,n-1);
    }
};