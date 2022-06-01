class Solution {
  bool isPalindrome(string A)
  {
    string B = "";
    B += A;
    reverse(B.begin(),B.end());
    return (A.compare(B) == 0);
  }
  
  string top_down_solution(string A, string B)
  {
    int n = A.length();
    int max_length = 0;
    int X = -1;
    int Y = -1;
    string res ;
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    int result = 0;
    for (int i = 1; i < dp.size(); i++)
    {
      for (int j = 1; j < dp[0].size(); j++)
      {
        // Basic Code for Longest Substring, combining it with the reverse of A string, should typically give the largest 
        // palindromic substring
        
       if (A[i-1] == B[j-1])
         dp[i][j] = 1 + dp[i-1][j-1];
        else
          dp[i][j] = 0;
        
        if (max_length < dp[i][j])
        {
          string temp = A.substr(i-dp[i][j],dp[i][j]);
          
          if (isPalindrome(temp))
          {
            max_length = dp[i][j];
            res = temp;
          }
        }
      }
    }
    return res;
  }
public:
    string longestPalindrome(string s) {
        string B = "";
      B += s;
      reverse(B.begin(),B.end());
      
      return top_down_solution(s,B);
    }
};