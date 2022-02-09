class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int rows = mat.size();
      
      if (rows == 0)
        return mat;
      
      int cols = mat[0].size();
      
      vector<vector<int>> dp(rows,vector<int>(cols,INT_MAX));
      
      queue<pair<int,int>> q;
      
      for (int i =0; i < rows;i++)
      {
        for (int j = 0; j < cols;j++)
        {
          if (mat[i][j] == 0)
          {
            dp[i][j] = 0;
            q.push({i,j});
          }
        }
      }
      
      int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
      
      while (!q.empty())
      {
        pair<int,int> curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
          int new_r = curr.first + dir[i][0];
          int new_c = curr.second + dir[i][1];
          
          if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols)
          {
            if (dp[new_r][new_c] > dp[curr.first][curr.second] + 1)
            {
              dp[new_r][new_c] = dp[curr.first][curr.second] + 1;
              q.push({new_r,new_c});
            }
          }
        }
      }
      return dp;
    }
};