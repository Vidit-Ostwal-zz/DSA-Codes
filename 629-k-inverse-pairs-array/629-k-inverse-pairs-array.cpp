class Solution {
  vector<vector<long long>> dp;
  
  int MOD = pow(10,9) + 7;
  
  long long Recursive_Solution(int n, int k)
  {
    if (k == 0)
      return dp[n][k] = 1;
    
    if (k < 0)
      return  0;
    
    if (n == 1)
      return dp[n][k] = 0;
    
    if (dp[n][k] != -1)
      return dp[n][k];
    
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
      answer += Recursive_Solution(n-1,k-i);
      answer = answer % MOD;
    }
    return dp[n][k] = answer % MOD;
  }
  
   void show_vector(vector<vector<long long>> vect)
{
  cout << "Printing Vector" << endl;
  cout <<" ---------------" << endl;
 for (int i = 0; i < vect.size(); i++)
 {
  for (int j = 0; j < vect[0].size(); j++)
   cout << vect[i][j] << " ";
  cout << endl;
 }
  cout << "Ending Vector" << endl;
}
public:
    int kInversePairs(int n, int k) {
      dp = vector<vector<long long>> (n+1,vector<long long>(k+1,-1));

      // long long answer = Recursive_Solution(n,k);
      // show_vector(dp);
      // return answer;
      
      for (int i = 0; i < dp.size(); i++)
      {
          vector<long long> prefix_dp;
       
        if (i)
        {
          int k = 0;
          long long prefix_sum = 0;
          
          while (k < i && k < dp[0].size())
          {
            prefix_sum += dp[i-1][k++];
            prefix_sum = prefix_sum % MOD;
            prefix_dp.push_back(prefix_sum);
          }
          
          int m = 0;
          while (k < dp[0].size())
          {
            prefix_sum += (dp[i-1][k++] - dp[i-1][m++]) % MOD;
            prefix_sum = prefix_sum % MOD;
            // prefix_sum -= dp[i-1][m++];
            // prefix_sum = prefix_sum % MOD;
           
            prefix_dp.push_back(prefix_sum);
          }
        }
        
        for (int j = 0; j < dp[0].size(); j++)
        {
          if (i == 0)
            dp[i][j] = 0;
          else if (j == 0)
            dp[i][j] = 1;
          else
            dp[i][j] = prefix_dp[j];
        }
      }
      
      // show_vector(dp);
      return (dp[n][k] + MOD)%MOD;
    }
};