class Solution {
public:
    int minDistance(string A, string B) {
      
      vector<vector<int>> dp(A.length()+1,vector<int>(B.length()+1,0));
      
      for (int i = 0; i < dp.size(); i++)
      {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (i == 0 || j == 0)
            {
              if (i == 0)
                dp[i][j] = j;
              else
                dp[i][j] = i;
            }

            else if (A[i-1] == B[j-1])
            dp[i][j] = dp[i-1][j-1];

            else
            dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
    }
  
      return dp[A.length()][B.length()];
    }
};