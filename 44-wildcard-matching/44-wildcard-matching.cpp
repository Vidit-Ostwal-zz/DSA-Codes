class Solution {
  vector<vector<int>> dp;
//   bool isPossible(string s, string p, int i, int j)
//   {
//     if (dp[i][j] != -1)
//       return (dp[i][j] == 1) ? true : false;
    
//     if (i == s.length() && j == p.length())
//       return dp[i][j] = true;
    
//     if (j == p.length())
//       return dp[i][j]= false;
    
//     if (i == s.length())
//     {
//       for (int k = j; k < p.length(); k++)
//         if (p[k] != '*')
//           return dp[i][j] = false;
      
//       return dp[i][j] = true;
//     }
    
//     if (p[j] == '?')
//       return dp[i][j] = isPossible(s,p,i+1,j+1);
    
//     if (p[j] >= 'a' && p[j] <= 'z')
//     {
//       if (p[j] == s[i])
//         return dp[i][j] = isPossible(s,p,i+1,j+1);
//       else
//         return dp[i][j] = false;
//     }
    
//     else
//       return dp[i][j] = isPossible(s,p,i+1,j) || isPossible(s,p,i+1,j+1) || isPossible(s,p,i,j+1);
//   }
public:
    bool isMatch(string s, string p) {
      dp = vector<vector<int>> (s.length()+1,vector<int>(p.length()+1,-1));
//       if (s.length() == 0)
//       {
//         for (int i = 0; i < p.length(); i++)
//           if (p[i] != '*')
//             return false;
        
//         return true;
//       }
      
      for (int i = 0; i < dp.size(); i++)
      {
        for (int j = 0; j < dp[0].size(); j++)
        {
          if (i == 0 && j == 0)
            dp[i][j] = true;
          
          else if (i == 0)
          {
            if (p[j-1] == '*')
              dp[i][j] = dp[i][j-1];
            else
              dp[i][j] = false;
          }
          
          else if (j == 0)
            dp[i][j] = false;
          
          else if (p[j-1] == '?')
            dp[i][j] = dp[i-1][j-1];
          
          else if (p[j-1] >= 'a' && p[j-1] <= 'z')
          {
            if (p[j-1] == s[i-1])
              dp[i][j] = dp[i-1][j-1];
            else
              dp[i][j] = false;
          }
            
          else
            dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
          
          // cout << dp[i][j] << "  ";
        }
        // cout << endl;
      }
      
      return dp[s.length()][p.length()];
    }
};