class Solution {
  int max_x;
  int max_y;
public:
  
  bool isvalid(int x, int y)
  {
    if (x >= 0 && y >= 0 && x <= max_x && y <= max_y)
      return true;
    
    return false;
  }
  
    int minimumEffortPath(vector<vector<int>>& heights) {
      max_x = heights.size()-1;
      max_y = heights[0].size()-1;
      
        /*Classical BFS Algorithm*/
      /*You push the element only when the distance is lower*/
      
      vector<vector<int>> map(heights.size(),vector<int>(heights[0].size(),INT_MAX));
      map[0][0] = 0;
      
      queue<pair<int,int>> q;
      q.push({0,0});
      
      while (!q.empty())
      {
        pair<int,int> pt = q.front();
        int x = pt.first;
        int y = pt.second;
        q.pop();
        
        if (isvalid(x+1,y))
        {
          int curr_eff = abs(heights[x+1][y] - heights[x][y]);
          if (map[x+1][y] > max(map[x][y],curr_eff))
          {
            map[x+1][y] = max(map[x][y],curr_eff);
            q.push({x+1,y});
          }
        }
        
        if (isvalid(x-1,y))
        {
          int curr_eff = abs(heights[x-1][y] - heights[x][y]);
          if (map[x-1][y] > max(map[x][y],curr_eff))
          {
            map[x-1][y] = max(map[x][y],curr_eff);
            q.push({x-1,y});
          }
        }
        
        if (isvalid(x,y+1))
        {
          int curr_eff = abs(heights[x][y+1] - heights[x][y]);
          if (map[x][y+1] > max(map[x][y],curr_eff))
          {
            map[x][y+1] = max(map[x][y],curr_eff);
            q.push({x,y+1});
          }
        }
        
        if (isvalid(x,y-1))
        {
          int curr_eff = abs(heights[x][y-1] - heights[x][y]);
          if (map[x][y-1] > max(map[x][y],curr_eff))
          {
            map[x][y-1] = max(map[x][y],curr_eff);
            q.push({x,y-1});
          }
        }
      }
      return map[heights.size()-1][heights[0].size()-1];
    }
};