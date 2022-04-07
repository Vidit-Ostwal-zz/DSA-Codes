class Solution {
  int recursive_solution(vector<vector<int>> matrix, int curr_row, int curr_col,vector<vector<int>>&dp)
  {
    cout << curr_row << "   " << curr_col << endl;
    if (curr_col < 0 || curr_col >= matrix[0].size())
      return INT_MAX;
    
    if (curr_row == matrix.size())
      return dp[curr_row][curr_col] = 0;
    
    if (dp[curr_row][curr_col] != -1)
      return dp[curr_row][curr_col];
    
    int answer = INT_MAX;
    
    if (curr_row == matrix.size() -1)
      answer = 0;
    else
    {
      for (int j = 0; j < matrix[0].size(); j++)
      {
        if (j != curr_col)
          answer = min(answer,recursive_solution(matrix,curr_row+1,j,dp));
      }
    }
    
    return dp[curr_row][curr_col] = matrix[curr_row][curr_col] + answer;
  }
public:
    int minFallingPathSum(vector<vector<int>>& dp) {
      if (dp.size() == 1 && dp[0].size() == 1)
        return dp[0][0];
      
      
      int curr_max = 0;
      int prev_max = 0;
      int curr_i = 0;
      int prev_i = 0;
      for (int i = 0; i < dp.size(); i++)
      {
        curr_max = INT_MAX;
        curr_i = INT_MAX;
        for (int j = 0; j < dp[0].size(); j++)
        {
          if (i == 0)
          {
            
          }
          else
          {
            if (j != prev_i)
              dp[i][j] += prev_max;
            else
            {
              int maxi = INT_MAX;
              for (int k= 0; k < dp[i-1].size() ; k++)
                if (k != j)
                  maxi = min(dp[i-1][k],maxi);
              
              dp[i][j] += maxi;
            }
          }
          
          if (dp[i][j] < curr_max)
          {
              curr_max = dp[i][j];
              curr_i = j;
          }
          // cout << dp[i][j] << "  " ;
        }
        prev_max = curr_max;
        prev_i = curr_i;
        // cout << endl;
      }
      return prev_max;
    }
};