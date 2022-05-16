class Solution {
  int n = 0;
  int m = 0;
  
  bool isValid(int x, int y)
  {
    return (x < n && x >= 0 && y < m && y >= 0);
  }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      if (grid[0][0])
        return -1;
      
      queue<pair<int,int>> pq;
      n = grid.size();
      m = grid[0].size();
      vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
      
      dis[0][0] = 1;
      pq.push(make_pair(0,0));
      
      while (!pq.empty())
      {
        auto it = pq.front();
        pq.pop();
        
        int x = it.first;
        int y = it.second;
        int w = dis[x][y];
        
        if (isValid(x+1,y) && !grid[x+1][y] && dis[x+1][y] > w+1)
        {
          dis[x+1][y] = w+1;
          pq.push(make_pair(x+1,y));
        }
        
        if (isValid(x-1,y) && !grid[x-1][y] && dis[x-1][y] > w+1)
        {
          dis[x-1][y] = w+1;
          pq.push(make_pair(x-1,y));
        }
        
        if (isValid(x,y+1) && !grid[x][y+1] && dis[x][y+1] > w+1)
        {
          dis[x][y+1] = w+1;
          pq.push(make_pair(x,y+1));
        }
        
        if (isValid(x,y-1) && !grid[x][y-1] && dis[x][y-1] > w+1)
        {
          dis[x][y-1] = w+1;
          pq.push(make_pair(x,y-1));
        }
        
        if (isValid(x+1,y+1) && !grid[x+1][y+1] && dis[x+1][y+1] > w+1)
        {
          dis[x+1][y+1] = w+1;
          pq.push(make_pair(x+1,y+1));
        }
        
        if (isValid(x-1,y+1) && !grid[x-1][y+1] && dis[x-1][y+1] > w+1)
        {
          dis[x-1][y+1] = w+1;
          pq.push(make_pair(x-1,y+1));
        }
        
        if (isValid(x+1,y-1) && !grid[x+1][y-1] && dis[x+1][y-1] > w+1)
        {
          dis[x+1][y-1] = w+1;
          pq.push(make_pair(x+1,y-1));
        }
        
        if (isValid(x-1,y-1) && !grid[x-1][y-1] && dis[x-1][y-1] > w+1)
        {
          dis[x-1][y-1] = w+1;
          pq.push(make_pair(x-1,y-1));
        }
        
      }
      
      return (dis[n-1][m-1] == INT_MAX) ? -1 : dis[n-1][m-1];
    }
};