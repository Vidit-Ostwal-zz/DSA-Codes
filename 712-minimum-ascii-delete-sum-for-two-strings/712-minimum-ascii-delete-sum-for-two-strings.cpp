class Solution {
  int get_LCS(string s1,string s2)
  {
    vector<vector<int>> dp (s1.length()+1,vector<int>(s2.length()+1,-1));
 
    for (int i = 0; i <= s1.length(); i++)
    {
      for (int j = 0 ;j <= s2.length(); j++)
      {
        if ( i == 0  || j == 0)
          dp[i][j] = 0;
        else if (s1[i-1] == s2[j-1])
          dp[i][j] = s1[i-1] + dp[i-1][j-1];
        else
          dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        
        // cout << dp[i][j] << "  ";
      }
      // cout << endl;
    }
    return dp[s1.length()][s2.length()];
//     string temp = "";
    
//     int i = s1.length();
//     int j = s2.length();
    
//     while (i && j)
//     {
//       if (s1[i-1] == s2[j-1])
//       {
//         temp = s1[i-1] + temp;
//         i--;
//         j--;
//       }
      
//       else if (dp[i-1][j] > dp[i][j-1])
//         i--;
//       else if (dp[i-1][j] < dp[i][j-1])
//         j--;
//       else
//       {
//         if (s1[i-1] > s2[j-1])
//           j--;
//         else
//           i--;
//       }
//     }
    
//     cout << temp << endl;
//     return temp;
  }
  
public:
    int minimumDeleteSum(string s1, string s2) {
        int s = get_LCS(s2,s1);
      
      int answer = 0;
      
      for (int i = 0; i < s1.length(); i++)
        answer += s1[i];
      
      for (int i = 0; i < s2.length(); i++)
        answer += s2[i];
      
//       for (int i=  0; i < s.length(); i++)
//         answer -= 2*s[i];
      
      return answer - 2*s;
    }
};