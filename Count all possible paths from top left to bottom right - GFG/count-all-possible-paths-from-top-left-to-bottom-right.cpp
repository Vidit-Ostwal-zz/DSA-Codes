// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  /*We Are going at each point, and calculating two path from that 
  Time Complexity = O(2^(N*M))
  Space Complexity = O(Path Length)*/
  int number_of_path(int m, int n)
  {
      if (m == 0 && n == 0)
      return 1;
      
      int left = 0;
      int up = 0;
      
      if (m > 0)
      up = number_of_path(m-1,n);
      
      if (n > 0)
      left = number_of_path(m,n-1);
      
      return left+up;
  }
  
  /*We Are going at each point, and calculating two path from that 
  Time Complexity = O(2^(N*M))
  Space Complexity = O(Path Length)*/
  int number_of_path_memo(int m, int n,vector<vector<int>> &dp)
  {
      int mod = pow(10,9)  + 7;
      if (m == 0 && n == 0)
      return 1;
      
      if (dp[m][n] != -1)
      {
          return dp[m][n];
      }
      int left = 0;
      int up = 0;
      
      if (m > 0)
      up = number_of_path_memo(m-1,n,dp)%mod;;
      
      if (n > 0)
      left = number_of_path_memo(m,n-1,dp)%mod;
      
      return dp[m][n] = (left+up)%mod;
  }
    long long int numberOfPaths(int m, int n){
        vector<vector<int>> dp (m,vector<int>(n,-1));
        return number_of_path_memo(m-1,n-1,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends