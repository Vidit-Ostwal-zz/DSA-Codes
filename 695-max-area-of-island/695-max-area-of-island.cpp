class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int answer = 0;
      
      for (int i = 0; i < grid.size(); i++)
      {
        for (int j = 0; j < grid[0].size(); j++)
        {
          if (grid[i][j] == 1)
          {
            queue<pair<int,int>> q;
            q.push(make_pair(i,j));
            int temp_area  = 0;
            
            while(!q.empty())
            {
              auto p = q.front();
              q.pop();
              
              
              int x = p.first;
              int y = p.second;
              
              if (grid[x][y])
              {
                temp_area++;
                grid[x][y] = 0;
                
                if (x+1 < grid.size() && grid[x+1][y])
                  q.push(make_pair(x+1,y));
                
                if (x-1 >= 0 && grid[x-1][y])
                  q.push(make_pair(x-1,y));
              
                if (y+1 < grid[0].size() && grid[x][y+1])
                  q.push(make_pair(x,y+1));
              
                if (y-1 >= 0 && grid[x][y-1])
                  q.push(make_pair(x,y-1));
              }
            }
            
            answer = max(answer,temp_area);
            // cout << answer << endl;
          }  
        }
      }
      
      return answer;
    }
};