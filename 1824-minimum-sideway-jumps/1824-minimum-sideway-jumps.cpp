class Solution {
public:
    int minSideJumps(vector<int>& obs) {
        vector<vector<int>> dp (obs.size(),vector<int>(3,-1));
      
      for (int i = 0; i < obs.size(); i++)
        if (obs[i] != 0)
          dp[i][obs[i]-1] = INT_MAX-1;
      
       for (int i = 0; i < dp.size()-1; i++)
       {
         if (i == 0)
         {
           dp[i][1] = 0;
           dp[i][0] = 1;
           dp[i][2] = 1;
         }
         else
         {
           if (obs[i] == 0)
           {
              dp[i][0] = min(dp[i][0],1 + min(dp[i][1],dp[i][2]));
              dp[i][1] = min(dp[i][1],1 + min(dp[i][0],dp[i][2]));
              dp[i][2] = min(dp[i][2],1 + min(dp[i][0],dp[i][1]));
           }
           
           else if (obs[i] == 1)
           {
              dp[i][1] = min(dp[i][1],1 + min(dp[i][0],dp[i][2]));
              dp[i][2] = min(dp[i][2],1 + min(dp[i][0],dp[i][1]));
           }
           
           else if (obs[i] == 2)
           {
              dp[i][0] = min(dp[i][0],1 + min(dp[i][1],dp[i][2]));
              dp[i][2] = min(dp[i][2],1 + min(dp[i][0],dp[i][1]));
           }
           
           else if (obs[i] == 3)
           {
              dp[i][0] = min(dp[i][0],1 + min(dp[i][1],dp[i][2]));
              dp[i][1] = min(dp[i][1],1 + min(dp[i][0],dp[i][2]));
           }
         }
         
         if (obs[i+1] != 1) dp[i+1][0] = dp[i][0];
         if (obs[i+1] != 2) dp[i+1][1] = dp[i][1];
         if (obs[i+1] != 3) dp[i+1][2] = dp[i][2];
         
         // cout << dp[i][0] << "   " << dp[i][1] << "   " << dp[i][2] << endl;
       }
      
      int n = dp.size()-1;
      return min(dp[n][0],min(dp[n][1],dp[n][2]));
    }
};