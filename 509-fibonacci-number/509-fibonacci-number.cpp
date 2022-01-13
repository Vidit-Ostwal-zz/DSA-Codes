class Solution {
public:
  
  /*Time Complexity = O(2^N)
  Space Complexity = O(N) Height of recursion*/
  int recursive_solution(int n)
  {
    if (n < 2)
      return n;
    return recursive_solution(n-1)+ recursive_solution(n-2);
  }
  
  /*Time Complexity = O(N)
  Space Complexity = O(N) Height of recursion stack and vector
  Top_down_approach*/
  int memoization_solution(int n,vector<int> &dp)
  {
    if (n < 2)
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
    for (int i = 0 ;i <= n; i++)
    {
      if (i <=1)
        dp[i] = i;
      
      else
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
  }
  
  
  /*Time Complexity = O(N)
  Space Complexity = O(1) */
  int bottom_up_solution_space_optimized(int n)
  {
    if (n < 2)
    {
      return n;
    }
    int a = 0;
    int b;
    int answer = 1;
    for (int i = 2 ;i <= n; i++)
    {
      b = answer;
      answer += a ;
      a = b; 
    }
    return answer;
  }
  
    int fib(int n) {
      /*used in memoization
      vector<int> dp(n+1,-1);
      */
        return bottom_up_solution_space_optimized(n);
    }
};