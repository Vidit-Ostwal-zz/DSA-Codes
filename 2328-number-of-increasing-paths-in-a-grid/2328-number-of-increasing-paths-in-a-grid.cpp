class Solution {
  vector<vector<long long>> dp;
  int m = 0;
  int n = 0;
  int MOD = 1000000007;
  
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
  
  long long Count(vector<vector<int>>& grid, int i, int j, int prev)
  {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= prev)
      return 0;
    
    if (dp[i][j] != -1)
      return dp[i][j];
    
    long long answer = Count(grid,i+1,j,grid[i][j])%MOD + Count(grid,i,j+1,grid[i][j])%MOD + Count(grid,i-1,j,grid[i][j])%MOD + Count(grid,i,j-1,grid[i][j])%MOD;
    answer++;
    return dp[i][j] = answer%MOD;
  }
public:
    int countPaths(vector<vector<int>>& grid) {
      
      m = grid.size();
      n = grid[0].size();
      long long answer = 0;
      
      dp = vector<vector<long long>>(m,vector<long long>(n,-1));
      
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            answer += Count(grid,i,j,-1);
      
      // show_vector(dp);
      return answer%MOD;;
    }
};