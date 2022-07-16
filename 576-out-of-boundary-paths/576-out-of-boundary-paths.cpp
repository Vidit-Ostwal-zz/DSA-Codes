class Solution {
  int MOD = pow(10,9) + 7;
  int X[4] = {-1,1,0,0};
  int Y[4] = {0,0,-1,1};
  
  vector<vector<vector<long long>>> dp;
  
  long long Paths(int m, int n, int maxMove, int x, int y)
  {
    if (x < 0 || y < 0 || x >= m || y >= n)
      return 1;
    
    if (!maxMove)
      return 0;
    
    if (dp[x][y][maxMove] != -1)
      return dp[x][y][maxMove];
    
    long long answer = 0;
    for (int i = 0; i < 4; i++)
    {
      answer += Paths(m,n,maxMove-1,x+X[i],y+Y[i]);
      answer = answer % MOD;
    }
    return dp[x][y][maxMove] = answer;
  }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
      dp = vector<vector<vector<long long>>>(m,vector<vector<long long>>(n,vector<long long>(maxMove+1,-1)));
        return Paths(m,n,maxMove,startRow,startColumn);
    }
};