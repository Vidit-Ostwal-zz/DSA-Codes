class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int count = -1;
      vector<vector<bool>> visited(isWater.size(),vector<bool>(isWater[0].size(),true));
      vector<vector<int>> dp(isWater.size(),vector<int>(isWater[0].size(),0));
      queue<pair<int,int>> q;
      
      for (int i = 0; i < isWater.size(); i++)
        for (int j = 0; j < isWater[0].size(); j++)
        {
          if (isWater[i][j])
            q.push({i,j});
        }
      int maxi = 0;
      while (!q.empty())
      {
        count++;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
          auto it = q.front();
          int x = it.first;
          int y = it.second;
          q.pop();
          
          if (visited[x][y])
          {
            visited[x][y] = false;
            dp[x][y] = count;
            
            if (x+1 < isWater.size() && visited[x+1][y])
              q.push(make_pair(x+1,y));
            
            if (x-1 >= 0 && visited[x-1][y])
              q.push(make_pair(x-1,y));
           
            if (y+1 < isWater[0].size() && visited[x][y+1])
              q.push(make_pair(x,y+1));
            
            if (y-1 >= 0 && visited[x][y-1])
              q.push(make_pair(x,y-1));
            
            maxi = max (maxi,dp[x][y]);
          }
        }
      }
      return dp;
    }
};