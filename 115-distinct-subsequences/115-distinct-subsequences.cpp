class Solution {
  vector<vector<double>> dp;
//   int RA(string s, string t, int i, int j)
//   {
//     if (j == t.length())
//       return 1;
    
//     if (i == s.length())
//       return 0;
    
//     if (dp[i][j] != -1)
//       return dp[i][j];
    
//     return dp[i][j] = (((s[i] == t[j]) ? RA(s,t,i+1,j+1) : 0) + RA(s,t,i+1,j));
    
//   }
public:
    int numDistinct(string s, string t) {
      dp = vector<vector<double>> (s.length()+1, vector<double>(t.length()+1,0));
        // return RA(s,t,0,0);
      
      for (int i = 0; i < dp.size(); i++)
      {
        for (int j = 0; j < dp[0].size(); j++)
        {
          if (j > i )
            dp[i][j] = 0;
          
          else if (j == 0)
            dp[i][j] = 1;
          
          else
            dp[i][j] = dp[i-1][j] + ((s[i-1] == t[j-1]) ? dp[i-1][j-1] : 0);
          
          // cout << dp[i][j] << "  ";
        }
        // cout << endl;
      }
      return dp[s.length()][t.length()];
    }
};