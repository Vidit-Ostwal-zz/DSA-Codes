class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
      vector<vector<pair<int,int>>> grid(m, vector<pair<int,int>>(n,make_pair(0,0)));
      
      for (int i = 0; i < walls.size(); i++)
      {
        int x = walls[i][0];
        int y = walls[i][1];
        grid[x][y].first = -2;
        grid[x][y].second = -2;
      }
      
      sort(guards.begin(),guards.end());
      
      for (int i = 0; i < guards.size(); i++)
      {
        int x = guards[i][0];
        int y = guards[i][1];
        
        /*Case when the cell was not marked yet, now the marking can be there too*/
        if (grid[x][y].first == 0 && grid[x][y].second == 0)
        {
          grid[x][y].first = -1;
          grid[x][y].second = -1;
        
          int i = x;
          int j = y;
          i--;
        
          while ( i >= 0 && grid[i][j].first != -2)
          {
            grid[i][j].first = -1;
            i--;
          }
          
          i = x;
          j = y;
          i++;
          
          while (i < grid.size() && grid[i][j].first != -2)
          {
            grid[i][j].first = -1;
            i++;
          }
          
          i = x;
          j = y;
          j--;
          
          while (j >= 0 && grid[i][j].first != -2)
          {
            grid[i][j].second = -1;
            j--;
          }
          
          i = x;
          j = y;
          j++;
          
          while (j < grid[0].size() && grid[i][j].first != -2)
          {
            grid[i][j].second = -1;
            j++;
          }
      }
        
        else if (grid[x][y].first == -1 && grid[x][y].second != -1)
        {
          grid[x][y].second = -1;
        
          int i = x;
          int j = y;
          j--;
          
          while (j >= 0 && grid[i][j].first != -2)
          {
            grid[i][j].second = -1;
            j--;
          }
          
          i = x;
          j = y;
          j++;
          
          while (j < grid[0].size() && grid[i][j].first != -2)
          {
            grid[i][j].second = -1;
            j++;
          }
        }
        
        else if (grid[x][y].first != -1 && grid[x][y].second == -1)
        {
          grid[x][y].first = -1;
        
          int i = x;
          int j = y;
          i--;
        
          while ( i >= 0 && grid[i][j].first != -2)
          {
            grid[i][j].first = -1;
            i--;
          }
          
          i = x;
          j = y;
          i++;
          
          while (i < grid.size() && grid[i][j].first != -2)
          {
            grid[i][j].first = -1;
            i++;
          }
        }
      }
        
      
      int count = 0;
      
      for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
          if (grid[i][j].first == 0 && grid[i][j].second == 0)
            count++;
      
      return count;
    }
};