class Solution {
  vector<int> dp_1;
  vector<int> dp_2;
  vector<vector<int>> dp;
  /*Memoization Code*/
  int max_profit(vector<int> P, int i,bool flag)
  {
    if (i == P.size())
      return 0;
    
    if (flag)
    {
      if (dp_1[i] != INT_MIN)
        return dp_1[i];
    }
    else
    {
      if (dp_2[i] != INT_MIN)
        return dp_2[i];
    }
    
    if (flag)
      return dp_1[i] = max(-1*P[i] + max_profit(P,i+1,!flag),max_profit(P,i+1,flag));
    else
      return dp_2[i] = max(P[i] + max_profit(P,i+1,!flag),max_profit(P,i+1,flag));
  }
public:
    int maxProfit(vector<int>& prices) {
//         int profit = 0;
      
//       for (int i = 1; i < prices.size(); i++)
//         if (prices[i] - prices[i-1] > 0)
//           profit += prices[i] - prices[i-1];
      
//       return profit;
      // dp_1 = vector<int>(prices.size(),INT_MIN);
      // dp_2 = vector<int>(prices.size(),INT_MIN);
      // return max_profit(prices,0,true);
      
      dp = vector<vector<int>>(prices.size()+1,vector<int>(2,INT_MIN));
      dp[0][1] = 0;
      
      for (int i= 1; i < dp.size(); i++)
        for (int j = 0; j < dp[0].size(); j++)
        {
          if (j == 0)
            dp[i][j] = max(dp[i-1][j],dp[i-1][1] - prices[i-1]);
          else
            dp[i][j] = max(dp[i-1][j],dp[i-1][0] + prices[i-1]);
        }
      return max(dp[dp.size()-1][0],dp[dp.size()-1][1]);
    }
};