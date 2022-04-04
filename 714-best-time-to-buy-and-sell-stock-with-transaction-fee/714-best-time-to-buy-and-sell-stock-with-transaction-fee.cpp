class Solution {
//   unordered_map<int,int> u1_true;
//   unordered_map<int,int> u1_false;
//   int max_profit (vector<int> p, int i,bool flag, int fee)
//   {
//     if (i == p.size())
//       return 0;
    
//     if (flag)
//     {
//        if (u1_true.find(i) != u1_true.end())
//          return u1_true[i];
//        return u1_true[i] = max (max_profit(p,i+1,!flag,fee)-p[i],max_profit(p,i+1,flag,fee));
//     }
     
//     if (u1_false.find(i) != u1_false.end())
//          return u1_false[i];
//     return u1_false[i] = max(max_profit(p,i+1,!flag,fee)+p[i]-fee,max_profit(p,i+1,flag,fee));
//   }
public:
    int maxProfit(vector<int>& prices, int fee) {
        // return max_profit (prices, 0,true,fee);
      
      vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
      
      dp[0][0] = -1 * (10000007); 
      dp[0][1] = 0;
      for (int i = 1; i <= prices.size(); i++)
      {
        for (int j = 0; j < 2; j++)
        {
          if (j == 0)
            dp[i][j] = max(dp[i-1][1] - prices[i-1],dp[i-1][0]);
          else
            dp[i][j] = max(dp[i-1][0] + prices[i-1] - fee,dp[i-1][1]);
        }
      }
      return dp[prices.size()][1];
    }
};