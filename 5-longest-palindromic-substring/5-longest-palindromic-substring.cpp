class Solution {
  bool isPalindrome (string temp)
  {
    string A = "";
    A += temp;
    reverse(A.begin(),A.end());
    return (temp.compare(A) == 0);
  }
  
  string LongestPalindromicSubstring(string A, string B)
  {
    vector<vector<int>> dp(A.length()+1,vector<int>(B.length()+1));
    
    for (int i = 1; i < dp.size(); i++)
    {
      for (int j = 1; j < dp[0].size(); j++)
      {
        if (A[i-1] == B[j-1])
          dp[i][j] = 1 + dp[i-1][j-1];
        else
          dp[i][j] = 0;
      }
    }
    
    int max_length = 0;
    string answer;
    for (int i = dp.size()-1; i >= 0; i--)
    {
      for (int j = dp[0].size()-1; j >= 0; j--)
      {
        if (dp[i][j] > max_length)
        {
          string temp = A.substr(i-dp[i][j],dp[i][j]);
          if (isPalindrome(temp))
          {
            max_length = dp[i][j];
            answer = temp;
          }
        }
      }
    }
    return answer;
  }
public:
    string longestPalindrome(string A) {
      string B = "";
      B += A;
      reverse(B.begin(),B.end());
        return LongestPalindromicSubstring(A,B);
    }
};