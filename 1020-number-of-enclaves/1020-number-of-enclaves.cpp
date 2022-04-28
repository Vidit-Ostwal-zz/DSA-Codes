class Solution {
  int X;
  int Y;
  
  bool check(int i, int j)
  {
    return (i >= 0 && i < X && j >= 0 && j < Y);
  }
  
  void doBFS(vector<vector<int>> grid, int i, int j, vector<vector<bool>>&vis)
  {
    queue<pair<int,int>> pq;
    pq.push(make_pair(i,j));
    vis[i][j] = false;
    
    while (!pq.empty())
    {
      auto it = pq.front();
      int x = it.first;
      int y = it.second;
      pq.pop();
      
      if (check(x+1,y) && grid[x+1][y] && vis[x+1][y])
      {
        pq.push(make_pair(x+1,y));
        vis[x+1][y] = false;
      }
      
      if (check(x,y+1) && grid[x][y+1] && vis[x][y+1])
      {
        pq.push(make_pair(x,y+1));
        vis[x][y+1] = false;
      }
      
      if (check(x-1,y) && grid[x-1][y] && vis[x-1][y])
      {
        pq.push(make_pair(x-1,y));
        vis[x-1][y] = false;
      }
      
      if (check(x,y-1) && grid[x][y-1] && vis[x][y-1])
      {
        pq.push(make_pair(x,y-1));
        vis[x][y-1] = false;
      }
    }
  }
public:
    int numEnclaves(vector<vector<int>>& grid) {
      X = grid.size();
      Y = grid[0].size();
      vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),true));
      
      for (int i = 0; i < grid.size(); i++)
      {
        if (grid[i][0] && visited[i][0])
          doBFS(grid,i,0,visited);
        
        if (grid[i][Y-1] && visited[i][Y-1])
          doBFS(grid,i,Y-1,visited);
      }
      
      for (int i = 0; i < grid[0].size(); i++)
      {
        if (grid[0][i] && visited[0][i])
          doBFS(grid,0,i,visited);
        
        if (grid[X-1][i] && visited[X-1][i])
          doBFS(grid,X-1,i,visited);
      }
      
      int count = 0;
      for (int i = 0; i < X; i++)
        for (int j=  0; j < Y; j++)
          if (grid[i][j] && visited[i][j])
            count++;
      
      return count;
    }
};