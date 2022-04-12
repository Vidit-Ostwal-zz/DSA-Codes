class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
      
      vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),true));
      
      queue<pair<int,int>> q;
      int m = grid.size()*grid[0].size();
      int count_land = 0;
      for (int i = 0; i < grid.size(); i++)
        for (int j=  0; j < grid[0].size(); j++)
        {
          if (grid[i][j] == 1)
          {
            count_land++;
            visited[i][j] = false;
            q.push(make_pair(i,j));
            m--;
          }
        }
      
      if (count_land == 0 || count_land == grid.size()*grid[0].size())
        return -1;
      
      int count = 0;
      
      while (!q.empty())
      {
        int size = q.size();
        count++;
        for (int i = 0; i < size; i++)
        {
          auto it = q.front();
          q.pop();
          int X = it.first;
          int Y = it.second;
          
          if (X-1 >= 0 && visited[X-1][Y])
          {
            visited[X-1][Y] = false;
            q.push(make_pair(X-1,Y));
            m--;
          }
          
          if (X+1 < visited.size() && visited[X+1][Y])
          {
            visited[X+1][Y] = false;
            q.push(make_pair(X+1,Y));
            m--;
          }
          
          if (Y-1 >=0 && visited[X][Y-1])
          {
            visited[X][Y-1] = false;
            q.push(make_pair(X,Y-1));
            m--;
          }
          
          if (Y+1 < visited[0].size() && visited[X][Y+1])
          {
            visited[X][Y+1] = false;
            q.push(make_pair(X,Y+1));
            m--;
          }
        }
      }
      if (m)
        return -1;
      
      return (count) ? count-1 : 0;
    }
};