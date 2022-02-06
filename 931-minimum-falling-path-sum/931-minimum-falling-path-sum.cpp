class Solution {
  int recursive_solution(vector<vector<int>> matrix, int curr_row, int curr_col,vector<vector<int>>&dp)
  {
    if (curr_col < 0 || curr_col >= matrix[0].size())
      return INT_MAX;
    
    if (curr_row == matrix.size())
      return 0;
    
    if (dp[curr_row][curr_col] != -1)
      return dp[curr_row][curr_col];
    
    
    return dp[curr_row][curr_col] = matrix[curr_row][curr_col] +  min(recursive_solution(matrix,curr_row+1,curr_col-1,dp),min(recursive_solution(matrix,curr_row+1,curr_col,dp),recursive_solution(matrix,curr_row+1,curr_col+1,dp)));
  }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
     /* int answer = INT_MAX;
      vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),-1));
      for (int i = 0; i < matrix[0].size(); i++)
        {
          answer = min(answer,recursive_solution(matrix,0,i,dp));
        }
      return answer;
    }
    */
    int answer = INT_MAX;
    for (int i = 1;i < matrix.size();i++)
    {
      for (int j = 0; j < matrix[0].size();j++)
      {
        if (j == 0)
          matrix[i][j] = matrix[i][j] + min(matrix[i-1][j],matrix[i-1][j+1]);
        
        else if (j == matrix[0].size()-1)
          matrix[i][j] = matrix[i][j] + min(matrix[i-1][j],matrix[i-1][j-1]);
        
        else
          matrix[i][j] = matrix[i][j] + min(matrix[i-1][j+1], min(matrix[i-1][j],matrix[i-1][j-1]));
      }
        
    }
      for (int j = 0; j < matrix[0].size();j++)
          answer = min(answer,matrix[matrix.size()-1][j]);
    return answer;
    }
};