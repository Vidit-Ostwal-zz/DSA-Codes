class Solution {
public:
    int maxProfit(vector<int>& prices) {
         vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
      
      dp[0][0] = -1 * (10000007); 
      dp[0][1] = 0;
      for (int i = 1; i <= prices.size(); i++)
      {
        for (int j = 0; j < 2; j++)
        {
          if (j == 0)
            dp[i][j] = max(dp[max(i-2,0)][1] - prices[i-1],dp[i-1][0]);
          else
            dp[i][j] = max(dp[i-1][0] + prices[i-1],dp[i-1][1]);
        }
      }
      return dp[prices.size()][1];
    }
};