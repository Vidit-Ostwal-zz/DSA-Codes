class Solution {
  int get_column(int start_col, int start_row,vector<vector<int>> grid, vector<vector<int>>&dp )
  {
    if (start_row == grid.size())
      return start_col;
    
    if (dp[start_row][start_col] != 0)
      return dp[start_row][start_col];
    
    if (start_col == 0 && grid[start_row][start_col] == -1)
      return dp[start_row][start_col] = -1;
    
    if (start_col == grid[0].size()-1 && grid[start_row][start_col] == 1)
      return dp[start_row][start_col] = -1;
    
    if (start_col+1 < grid[0].size() && grid[start_row][start_col] == 1 && grid[start_row][start_col+1] == -1)
      return dp[start_row][start_col] = -1;
    
    if (start_col >0 && grid[start_row][start_col] == -1 && grid[start_row][start_col-1] == 1)
      return dp[start_row][start_col] = -1;
    
    if (start_col+1 < grid[0].size() && grid[start_row][start_col] == 1 && grid[start_row][start_col+1] == 1)
      return dp[start_row][start_col] = get_column(start_col+1,start_row+1,grid,dp);
    
    if (start_col > 0 && grid[start_row][start_col] == -1 && grid[start_row][start_col-1] == -1)
      return dp[start_row][start_col] = get_column(start_col-1,start_row+1,grid,dp);
    
    return INT_MAX;
  }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
      /*vector<int> final_vector;  
      vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
      for (int i = 0; i < grid[0].size(); i++)
          final_vector.push_back(get_column(i,0,grid,dp));
      
      return final_vector;
      */
      
      vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
      
      for (int i = grid.size()-1;i >= 0; i--)
      {
        for (int j = 0; j < grid[0].size(); j++)
        {
          if (i == grid.size() - 1)
          {
            if (j == 0 && grid[i][j] == -1)
              dp[i][j] = -1;
            
            else if (j == grid[0].size()-1 && grid[i][j] == 1)
              dp[i][j] = -1;
            
            else if (grid[i][j] == 1 && grid[i][j+1] == -1)
              dp[i][j] = -1;
            
            else if (grid[i][j] == -1 && grid[i][j-1] == 1)
              dp[i][j] = -1;
            
            else if (grid[i][j] == 1)
              dp[i][j] = j+1;
            
            else if (grid[i][j] == -1)
              dp[i][j] = j-1;
          }
          
          else 
          {
            if (j == 0 && grid[i][j] == -1)
              dp[i][j] = -1;
            
            else if (j == grid[0].size()-1 && grid[i][j] == 1)
              dp[i][j] = -1;
            
            else if (grid[i][j] == 1 && grid[i][j+1] == -1)
              dp[i][j] = -1;
            
            else if (grid[i][j] == -1 && grid[i][j-1] == 1)
              dp[i][j] = -1;
            
            else if (grid[i][j] == 1)
              dp[i][j] = dp[i+1][j+1];
            
            else if (grid[i][j] == -1)
              dp[i][j] = dp[i+1][j-1];
          }
        }
      }
      for (int i = 0; i < dp.size(); i++)
      {
        for (int j = 0; j < dp[0].size(); j++)
          cout << dp[i][j] << "  ";
        
        cout << endl;
      }
      
      return dp[0];
    }
};