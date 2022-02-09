class Solution {
public:
    int countSubstrings(string s) {
        int length = s.length();
      
      vector<vector<bool>> dp(length,vector<bool>(length,false));
      
      for (int i = 0; i < length; i++)
        dp[i][i] = true;
      
      for (int i = 1; i < length;i++)
        if (s[i] == s[i-1])
          dp[i-1][i] = true;
      
      int count = 0; 
      for (int i = length-1; i >= 0; i--)
      {
        for (int j = length-1; j >=i; j--)
        {
          if (i == j)
          {
            dp[i][j] = true;
          }
            
          else if (j - i == 1)
          {
            if (s[i] == s[j])
              dp[i][j] = true;
          }
          
          else if (dp[i+1][j-1] && (s[i] == s[j]))
          {
            dp[i][j] = true;
          }
          
          else
          {}
          
          
          if (dp[i][j])
            count++;
  
        }
        cout << endl;
      }
      return count;
    }
};