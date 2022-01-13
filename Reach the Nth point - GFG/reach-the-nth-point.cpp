// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	/*Time Complexity = O(2^N)
  Space Complexity = O(N) Height of recursion*/
  int recursive_solution(int n)
  {
    if (n <= 2)
      return n;
    return recursive_solution(n-1)+ recursive_solution(n-2);
  }
	
  /*Time Complexity = O(N)
  Space Complexity = O(N) Height of recursion stack and vector
  Top_down_approach*/
  int memoization_solution(int n,vector<int> &dp)
  {
    if (n <= 2)
      return n;
    
    if (dp[n] != -1)
    {
      return dp[n];
    }
    return dp[n] = memoization_solution(n-1,dp)+ memoization_solution(n-2,dp);
  }
  
  /*Time Complexity = O(N)
  Space Complexity = O(N) vector*/
  int bottom_up_solution(int n)
  {
    vector<int> dp(n+1);
    int mod = pow(10,9)+7;
    for (int i = 1;i <= n; i++)
    {
      if (i <=2)
        dp[i] = i;
      
      else
        dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod ;
    }
    return dp[n];
  }
  
  /*Time Complexity = O(N)
  Space Complexity = O(1) */
  int bottom_up_solution_space_optimized(int n)
  {
    if (n <= 2)
    {
      return n;
    }
    int mod = pow(10,9)+7;
    int a = 1;
    int b;
    int answer = 2;
    for (int i = 3;i <= n; i++)
    {
      b = answer%mod;
      answer = (answer% mod + a%mod)%mod ;
      a = b; 
    }
    return answer;
  }
		int nthPoint(int n){
		    /*
		    vector<int> dp(n+1,-1);
		    */
		    return bottom_up_solution_space_optimized(n);
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends