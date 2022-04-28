class Solution {
  int X;
  int Y;
  
  bool check(int x, int y)
  {
    return (x >= 0 && y >= 0 && x < X && y < Y);
  }
  
  void do_BFS(vector<vector<int>> grid, int x, int y, vector<vector<bool>> &vis)
  {
    queue<pair<int,int>> pq;
    pq.push(make_pair(x,y));
    vis[x][y] = false;
    
    while (!pq.empty())
    {
      auto it = pq.front();
      pq.pop();
      
      int i = it.first;
      int j = it.second;
      
      if (check(i+1,j) && !grid[i+1][j] && vis[i+1][j])
      {
        vis[i+1][j] = false;
        pq.push(make_pair(i+1,j));
      }
      
      if  (check(i,j+1) && !grid[i][j+1] && vis[i][j+1])
      {
        vis[i][j+1] = false;
        pq.push(make_pair(i,j+1));
      }
     
      if (check(i-1,j) && !grid[i-1][j] && vis[i-1][j])
      {
        vis[i-1][j] = false;
        pq.push(make_pair(i-1,j));
      }
      
      if  (check(i,j-1) && !grid[i][j-1] && vis[i][j-1])
      {
        vis[i][j-1] = false;
        pq.push(make_pair(i,j-1));
      }
    }
    
  }
public:
    int closedIsland(vector<vector<int>>& grid) {
      X = grid.size();
      Y = grid[0].size(); 
      int count = 0;
      vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),true));
      
      for (int i = 0; i < X; i++)
      {
        if (!grid[i][0])
          do_BFS(grid,i,0,vis);
        
        if (!grid[i][Y-1])
          do_BFS(grid,i,Y-1,vis);
      }
      
      for (int j = 0; j < Y; j++)
      {
        if (!grid[0][j])
          do_BFS(grid,0,j,vis);
        
        if (!grid[X-1][j])
          do_BFS(grid,X-1,j,vis);
      }
      
      for (int i = 1; i < X; i++)
        for (int j = 1; j < Y; j++)
          if (!grid[i][j] && vis[i][j])
          {
            do_BFS(grid,i,j,vis);
            count++;
          }
      
      return count;
    }
};