class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      
      /*Dp matrix initialization*/
      vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));
      
      int answer = 0;
      /*The cell is thoguht as the rightmost bottom cell to solve the problem*/
      for (int i = 0; i < matrix.size(); i++)
      {
        for (int j = 0; j < matrix[0].size(); j++)
        {
          if (i == 0 || j == 0)
            dp[i][j] = matrix[i][j]-'0';
          
          else if (matrix[i][j] == '0')
            dp[i][j] = 0;
          
          else
            dp[i][j] = matrix[i][j]-'0' + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
          
          cout << dp[i][j] << "   " ;
          answer = max(answer,dp[i][j]);
        } 
        cout << endl;
      }
      return answer*answer;
    }
};