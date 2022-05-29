class Solution {
  bool check(int i, int j, int m, int n)
  {
    return (i >= 0 && j >= 0 && i < m && j < n);
  }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
      int m = grid.size();
      int n = grid[0].size();
      int X[4] = {1,-1,0,0};
      int Y[4] = {0,0,1,-1};
      
      
      vector<vector<int>> r_obs(m,vector<int>(n,INT_MAX));
      queue<pair<int,int>>pq;
      r_obs[0][0] = 0;
      
      pq.push(make_pair(0,0));
      while (!pq.empty())
      {
        int x = pq.front().first;
        int y = pq.front().second;
        pq.pop();
        
        int temp_r = r_obs[x][y];
        for (int k =0; k < 4; k++)
        {
          int x_new = x + X[k];
          int y_new = y + Y[k];
          
          if (check(x_new, y_new, m,n))
          {
            int r_new = temp_r+grid[x_new][y_new];
            
            if (r_obs[x_new][y_new] > r_new)
            {
              r_obs[x_new][y_new] = r_new;
              pq.push(make_pair(x_new,y_new));
            }
          }
        }
      }
      return r_obs[m-1][n-1];
    }
};