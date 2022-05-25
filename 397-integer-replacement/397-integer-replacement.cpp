class Solution {
  long long  Recursive(long long n)
  {
    if (pow(2,(int)log2(n)) == n)
      return log2(n);
    
    if (n%2)
      return (long long)1+ min(Recursive(n+1),Recursive(n-1));
    
    return (long long)1 + Recursive(n/2);
  }
public:
    int integerReplacement(int n) {
      return (int)Recursive(n);
         vector<int>dp = vector<int>(n+2,-1);
      
      dp[1] = 0;
      for (int i = 2; i < dp.size(); i++)
      {
        if (i%2)
        {
          int l = (i-1);
          int h = (i+1)/2;
          
          dp[i] = 1 + min(dp[l],1+dp[h]);
        }
        else
        {
          dp[i] = 1 + dp[i/2];
        }
        // cout << i <<  "     " << dp[i] << endl;
      }
      return dp[n];
    }
};