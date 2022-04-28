class Solution {
  
  /*classical BFS Algorithm, now problem is we can approach a particular cell form multiple sides, so maintaining a visited vector won't help as we might need to visit it again, therefore we need to make a distance vector adn push when ever this distance will be lesser than the curr one, and this contniuse as long as possible*/
  
  int X;
  int Y;
  
  bool isValid(int x, int y)
  {
    return (x >= 0 && x < X && y >= 0 && y < Y);
  }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      vector<vector<int>> dis(heights.size(),vector<int>(heights[0].size(),INT_MAX));
      X = heights.size();
      Y = heights[0].size();
      
      dis[0][0] = 0;
      
      queue<pair<int,int>> pq;
      pq.push(make_pair(0,0));
      
      while (!pq.empty())
      {
        int x = pq.front().first;
        int y = pq.front().second;
        // cout << x  << "   " << y << endl;
        int temp1 = dis[x][y];
        int temp = 0;
        pq.pop();
        
        if (isValid(x+1,y))
        {
          if ( max(dis[x][y],abs(heights[x+1][y] - heights[x][y])) < dis[x+1][y])
          {
            dis[x+1][y] = max(temp1,abs(heights[x+1][y] - heights[x][y]));
            pq.push(make_pair(x+1,y));
          }
        }
        
        if (isValid(x,y+1))
        {
          if ( max(dis[x][y],abs(heights[x][y+1] - heights[x][y])) < dis[x][y+1])
          {
            dis[x][y+1] = max(temp1,abs(heights[x][y+1] - heights[x][y]));
            pq.push(make_pair(x,y+1));
          }
        }
        
        if (isValid(x-1,y))
        {
          if ( max(dis[x][y], abs(heights[x-1][y] - heights[x][y])) < dis[x-1][y])
          {
            dis[x-1][y] = max(temp1,abs(heights[x-1][y] - heights[x][y]));
            pq.push(make_pair(x-1,y));
          }
        }
        
        if (isValid(x,y-1))
        {
          if ( max(dis[x][y] , abs(heights[x][y-1] - heights[x][y])) < dis[x][y-1])
          {
            dis[x][y-1] = max(temp1, abs(heights[x][y-1] - heights[x][y]));
            pq.push(make_pair(x,y-1));
          }
        }
      }
      
      return dis[X-1][Y-1];
    }
};