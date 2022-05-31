class Solution {
public:
  /*
  Time Compleixty = O(2^N)
  Sapce Complexity = O(N) Recursion Stack Space*/
  int recursive_solution(string text1, string text2, int index1, int index2)
  {
    if (index1 == text1.length() || index2 == text2.length())
      return 0;
    
    if (text1[index1] == text2[index2])
    {
      return 1 + recursive_solution(text1,text2,index1+1,index2+1);
    }
    
    else
    {
      return max(recursive_solution(text1,text2,index1,index2+1), recursive_solution(text1,text2,index1+1,index2));
    }
    
    return 0;
  }

  /*
  Time Compleixty = O(2^N)
  Sapce Complexity = O(N) Recursion Stack Space*/
  int memoization_solution(string text1, string text2, int index1, int index2,vector<vector<int>> &dp)
  {
    if (index1 == text1.length() || index2 == text2.length())
      return 0;
    
    if (dp[index1][index2] != -1)
      return dp[index1][index2];
    
    if (text1[index1] == text2[index2])
    {
      return dp[index1][index2] = 1 + memoization_solution(text1,text2,index1+1,index2+1,dp);
    }
    
    return  dp[index1][index2] = max(memoization_solution(text1,text2,index1,index2+1,dp), memoization_solution(text1,text2,index1+1,index2,dp));
  }
  
  /*
  Time Compleixty = O(2^N)
  Sapce Complexity = O(N) Recursion Stack Space*/
//   int top_down_solution(string text1, string text2)
//   {
//     vector<vector<int>> dp(text1.length()+1,vector<int> (text2.length()+1,-1));
//     for (int i = 0; i <= text1.length();i++)
//     {
//       for (int j = 0; j <= text2.length(); j++)
//       {
//         if (i == 0 || j == 0)
//           dp[i][j] = 0;
        
//         else
//           dp[i][j] = (text1[i-1] == text2[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i-1][j],dp[i][j-1]);
//       }
//     }
//     return dp[text1.length()][text2.length()];
//   }
 
 int top_down_solution (string s, string t)
 {
   vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,0));
   
   for (int i = 1; i < dp.size(); i++)
   {
     for (int j = 1; j < dp[0].size(); j++)
     {
       if (s[i-1] == t[j-1])
         dp[i][j] = 1 + dp[i-1][j-1];
       else
         dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
     }
   }
   return dp[s.length()][t.length()];
 }
    int longestCommonSubsequence(string text1, string text2) {
      /*
      vector<vector<int>> dp(text1.length(),vector<int> (text2.length(),-1));
      */
      return top_down_solution(text1,text2);
    }
};