class Solution {
  int diff_ways(string s, int index,vector<int>&dp)
  {
    if (s[index] - '0' == 0)
        return 0;
    
    if (index >= s.length() - 1 )
      return 1;
    
    if (dp[index] != -1)
      return dp[index];
    
    if (s[index+1] - '0' == 0)
    {
      if (((s[index] - '0')*10 + (s[index+1] - '0')) > 26)
        return 0;
      
      return diff_ways(s,index+2,dp);
    }
      
    
    int option1 = diff_ways(s,index+1,dp);
    int option2 = (s[index] - '0')*10 + (s[index+1] - '0') <=26 ? diff_ways(s,index+2,dp) : 0;
    
    return dp[index] = option1+option2;
  }
public:
    int numDecodings(string s) {
      
      vector<int> dp(s.length(),-1);
      return diff_ways(s, 0,dp);
    }
};