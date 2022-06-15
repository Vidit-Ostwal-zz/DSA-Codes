class Solution {
  vector<vector<int>> visited;
  vector<vector<bool>> dp;
  bool Helper (string A ,string B, int indexA,int indexB)
  {
    if (indexB == B.length() && indexA == A.length())
      return true;
    
    if (indexB == B.length() && indexA != A.length())
      return false;
  
    if (visited[indexA][indexB] != -1)
      return dp[indexA][indexB];
    
    visited[indexA][indexB] = 0;
    
    if (indexA == A.length() && indexB != B.length())
    {
      while (indexB < B.length())
      {
        if (B[indexB] != '*')
          return dp[indexA][indexB] = false;
        indexB++;
      }
      return dp[indexA][indexB] = true;
    }
    
    if (A[indexA] == B[indexB] || B[indexB] == '?')
      return dp[indexA][indexB] = Helper(A,B,indexA+1,indexB+1);
    
    if (B[indexB] == '*')
      return dp[indexA][indexB] = Helper(A,B,indexA+1,indexB+1) || Helper(A,B,indexA+1,indexB) || Helper(A,B,indexA,indexB+1);
    
    return dp[indexA][indexB] = false;
  }
public:
    bool isMatch(string s, string p) {
      // visited = vector<vector<int>> (s.length()+1,vector<int>(p.length()+1,-1));
      dp = vector<vector<bool>> (s.length()+1,vector<bool>(p.length()+1,false));
      
      for (int i = 0; i < dp.size(); i++)
        for (int j = 0; j < dp[0].size(); j++)
        {
          // Empty string empty
          if (i == 0 && j == 0)
            dp[i][j] = true;
          
          // input string non empty while pattern is something
          else if( i == 0)
          {
            if (p[j-1] == '*')
              dp[i][j] = dp[i][j-1];
            else
              dp[i][j] = false;
          }
          
          // pattern is empty but string is not.
          else if (j == 0)
            dp[i][j] = false;
          
          else if (s[i-1] == p[j-1] || p[j-1] == '?')
            dp[i][j] = dp[i-1][j-1];
          
          else if (p[j-1] == '*')
            dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
          
          else
            dp[i][j] = false;
        }
      
      return dp[s.length()][p.length()];
        // return Helper(s,p,0,0);
    }
};