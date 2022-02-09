class Solution {
public:
  int min_path(int m, int n,vector<vector<int>> grid)
  {
      vector<vector<int>> dp (m+1,vector<int>(n+1,-1));
    
    for (int i = 0; i <= m; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        if (i == 0 || j == 0)
        {
          int temp = 0;
          if (i > 0)
          {
            temp = dp[i-1][j];
          }
          else if (j > 0)
          {
            temp = dp[i][j-1];
          }
          dp[i][j] = grid[i][j]+ temp;
        }
        else
          dp[i][j] = grid[i][j] + min(dp[(i-1)][j],dp[i][j-1]);
      }
    }
    return dp[m][n];
  }
  
    int minPathSum(vector<vector<int>>& grid) {
        return min_path(grid.size()-1,grid[0].size()-1,grid);
    }
};