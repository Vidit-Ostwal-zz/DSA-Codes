class Solution {
  /*Time Complexity=  O(2^N)
  Space Complexity = O(N)*/
//   int via_recursion(int n)
//   {
//     if (n <= 1)
//       return n;
    
//     return via_recursion(n-1) + via_recursion(n-2);
//   }
  
  vector<int> memo;
  /*Time Compleixty = O(N)
  Space Compexity = O(N)*/
//   int via_memoization (int n)
//   {
//     cout << n << endl;
//     if (n <= 1)
//       return memo[n] = n;
    
//     if (memo[n] != -1)
//       return memo[n];
    
//     return memo[n] = (via_memoization(n-1) + via_memoization(n-2));
//   }
  
  /*Time Compleixty = O(N)
  Space Compexity = O(N)*/
  int top_down (int n)
  {
    if (n <=1)
      return n;
    
    vector<int> top(n+1,-1);
    
    top[0] = 0;
    top[1] = 1;
    
    for (int i = 2; i < top.size(); i++)
      top[i] = top[i-1] + top[i-2];
    
    return top[n];
  }
  
  /*Time Complexity = O(N)
  Space Complexity = O(1)*/
  int top_down_space(int n)
  {
    if (n < 2)
      return n;
    
    int prev2 = 0;
    int prev1 = 1;
    int temp = 0;
    for (int i = 2; i <= n; i++)
    {
      temp = prev1+prev2;
      prev2 = prev1;
      prev1 = temp;
    }
    return prev1;
  }
public:
    int fib(int n) {
      memo = vector<int>(n+1,-1);
        // return via_recursion(n);
      return top_down(n); 
    }
};