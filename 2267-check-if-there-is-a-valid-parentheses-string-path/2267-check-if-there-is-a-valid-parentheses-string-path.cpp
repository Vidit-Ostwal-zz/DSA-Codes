class Solution {
  vector<vector<vector<int>>> dp;
  int m;  
  int n;
  
  int checkallPath(vector<vector<char>>& grid, int i, int j, int k)
  {
    
    if (i >= m || j >= n)
      return 0;
    
    // cout << i << j << endl;
    int temp_k = k;
    
    if (grid[i][j] == '(')
      k++;
    else
      k--;
    
    if (k < 0)
      return 0;
    
    if (i == m-1 && j == n-1)
      return (k==0);
    
    if (dp[i][j][temp_k] != -1)
      return dp[i][j][temp_k];
    
    return dp[i][j][temp_k] = checkallPath(grid,i+1,j,k) || checkallPath(grid,i,j+1,k);
  
  }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
      
      m = grid.size();
      n = grid[0].size();
      dp = vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(205,-1)));
     
      return checkallPath(grid,0,0,0);
    }
};