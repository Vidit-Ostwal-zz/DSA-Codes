class Solution {
public:
  /*Example*/
    string longestPalindrome(string s) {
        int length = s.length();
      vector<vector<int>> dp(length,vector<int>(length,0));
      
      for (int i = 0; i < length; i++)
        dp[i][i] = 1;
      
      for (int i = 1; i < length;i++)
        if (s[i] == s[i-1])
          dp[i-1][i] = 2;
      
      int answer = INT_MIN;
      int x = -1;
      int y = -1;
      for (int i = length-1; i >= 0; i--)
      {
        for (int j = length-1; j >=i; j--)
        {
          if (i == j)
            dp[i][j] = 1;
            
          else if (j - i == 1)
          {
            if (s[i] == s[j])
              dp[i][j] = 2;
          }
          
          else if (dp[i+1][j-1] && (s[i] == s[j]))
            dp[i][j] = 2 + dp[i+1][j-1];
          
          else
          {}
          
          if (answer < dp[i][j])
          {
            answer = dp[i][j];
            x = i;
            y = j;
          }
        }
      } 
      
      string temp = "";
      while (x <= y)
      {
        temp += s[x];
        x++;
      }
      
      return temp;
    }
};