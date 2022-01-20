class Solution {
public:
  int number_of_path_tabu(int m, int n,vector<vector<int>>& obstacleGrid)
  {
    
      vector<vector<int>> dp (m+1,vector<int>(n+1,-1));
      
    for (int i = 0; i <= m; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        if (obstacleGrid[i][j] == 1)
          dp[i][j] = 0;
        
        else if (i == 0 || j == 0)
        {
          if (i == 0 && j == 0)
            dp[i][j] = 1;
          
          else if (i == 0)
            dp[i][j] = dp[i][j-1];
          
          else if (j == 0)
            dp[i][j] = dp[i-1][j];
        }
        
        else
          dp[i][j] = dp[(i-1)][j] + dp[i][j-1];
      }
    }
    return dp[m][n];
  }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
        return number_of_path_tabu(m-1,n-1,obstacleGrid);
    }
};