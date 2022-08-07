class Solution {
public:
    int countVowelPermutation(int n) {
        
      vector<vector<long long>> dp(5,vector<long long>(n,0));
      long long answer = 0;
      int MOD = pow(10,9) + 7;
      
      for (int j = 0; j < n; j++)
      {
        for (int i = 0; i < 5; i++)
        {
          if (j == 0)
            dp[i][j] = 1;
          else if (i == 0)
            dp[i][j] = dp[1][j-1] + dp[2][j-1] + dp[4][j-1];
          else if (i == 1)
            dp[i][j] = dp[0][j-1] + dp[2][j-1];
          else if (i == 2)
            dp[i][j] = dp[1][j-1] + dp[3][j-1];
          else if (i == 3)
            dp[i][j] = dp[2][j-1];
          else if (i == 4)
            dp[i][j] = dp[2][j-1] + dp[3][j-1];
          
          dp[i][j] = dp[i][j] % MOD;
          
          if (j == n-1)
            answer += dp[i][j];
          
          answer = answer % MOD;
        }
      }
      return answer;
     
    }
};