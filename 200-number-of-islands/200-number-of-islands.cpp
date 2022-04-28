class Solution {
//   void change(vector<vector<char>> grid, vector<vector<bool>> & flag, int x, int y)
//   {
//     queue<pair<int,int>> q;
//     q.push(make_pair(x,y));
    
//     while (!q.empty())
//     {
//       int size = q.size();
      
//       for (int i = 0; i < size; i++)
//       {
//         auto it = q.front();
//         q.pop();
//         int x = it.first;
//         int y = it.second;
//         flag[x][y] = false;
        
//         if ((x+1 < grid.size()) && (grid[x+1][y] == '1') && flag[x+1][y])
//           q.push(pair(x+1,y));
        
//          if (x-1 >= 0 && grid[x-1][y] == '1' && flag[x-1][y])
//           q.push(pair(x-1,y));
        
//          if (y+1 < grid[0].size() && grid[x][y+1] == '1' && flag[x][y+1])
//           q.push(pair(x,y+1));
        
//          if (y-1 >= 0 && grid[x][y-1] == '1' && flag[x][y-1])
//           q.push(pair(x,y-1));
//       }
//     }
//   }
  
public:
    int numIslands(vector<vector<char>>& grid) {
      vector<vector<bool>> flag(grid.size(),vector<bool>(grid[0].size(),true));
      
      int count  = 0;
      for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
        {
          if (grid[i][j] == '1' && flag[i][j])
          {
            count++;
            queue<pair<int,int>> q;
            q.push(make_pair(i,j));
            flag[i][j] = false;
            
            while (!q.empty())
            {
              int size = q.size();      
              for (int i = 0; i < size; i++)   
              {        
                auto it = q.front();      
                q.pop();
        
                int x = it.first;
                int y = it.second;
        
                if ((x+1 < grid.size()) && (grid[x+1][y] == '1') && flag[x+1][y])
                {
                  q.push(pair(x+1,y));
                  flag[x+1][y] = false;
                }
                
                if (x-1 >= 0 && grid[x-1][y] == '1' && flag[x-1][y])
                {
                  q.push(pair(x-1,y));
                  flag[x-1][y] = false;
                }
        
                if (y+1 < grid[0].size() && grid[x][y+1] == '1' && flag[x][y+1])
                {
                  q.push(pair(x,y+1));
                  flag[x][y+1] = false;
                }
        
                if (y-1 >= 0 && grid[x][y-1] == '1' && flag[x][y-1])
                {
                  q.push(pair(x,y-1));
                  flag[x][y-1] = false;
                }
              }
            }
          }
        }
      return count;
    }
};