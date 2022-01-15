// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
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
  int top_down_solution(string text1, string text2)
  {
    int result = 0;
    vector<vector<int>> dp(text1.length()+1,vector<int> (text2.length()+1,-1));
    for (int i = 0; i <= text1.length();i++)
    {
      for (int j = 0; j <= text2.length(); j++)
      {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        
        else if (text1[i-1] == text2[j-1])
          {
              dp[i][j] = 1 + dp[i-1][j-1];
              result = max(result,dp[i][j]);
          }
          
        else
          dp[i][j] = 0;
      }
    }
    
    return result;
  }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        return top_down_solution(S1,S2);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends