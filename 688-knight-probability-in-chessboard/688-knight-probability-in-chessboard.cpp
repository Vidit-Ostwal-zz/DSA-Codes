class Solution {
  // long long sum = 0;
  vector<vector<vector<double>>> dp;
  double find_next(int n, int k, int r, int c)
  {
    if (r <0 || r >= n || c < 0 || c >= n)
      return 0;
    
    if (k == 0)
      return 1;
    
    if (dp[r][c][k] != -1)
      return dp[r][c][k];
    
    double answer = 0;
    
    answer += find_next(n,k-1,r+1,c+2);
    answer += find_next(n,k-1,r+2,c+1);
    answer += find_next(n,k-1,r-1,c-2);
    answer += find_next(n,k-1,r-2,c-1);
    answer += find_next(n,k-1,r+1,c-2);
    answer += find_next(n,k-1,r-2,c+1);
    answer += find_next(n,k-1,r-1,c+2);
    answer += find_next(n,k-1,r+2,c-1);
    
    return dp[r][c][k] = answer;
  }
public:
    double knightProbability(int n, int k, int row, int col) {
      
      dp = vector<vector<vector<double>>>(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
      double sum  = find_next(n,k,row,col);
      
      return (double)sum/pow(8,k);
    }
};