class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      int MOD = pow(10,9)+7;
      
      vector<vector<pair<long long ,long long>>> matrix(m,vector<pair<long long,long long>>(n,make_pair(0,0)));
      
      for (int i = 0; i < m ; i++)
        for (int j = 0; j < n; j++)
        {
          // cout << i << "   " << j << endl;
          if (i == 0 && j == 0)
          {
            matrix[i][j].first = grid[i][j];
            matrix[i][j].second = grid[i][j];
          }
          
          else if (i == 0)
          {
            matrix[i][j].first = grid[i][j] * matrix[i][j-1].first;
            matrix[i][j].second = grid[i][j] * matrix[i][j-1].second;
          }
          
          else if (j == 0)
          {
            matrix[i][j].first = grid[i][j] * matrix[i-1][j].first;
            matrix[i][j].second = grid[i][j] * matrix[i-1][j].second;
          }
          
          else 
          {
            if (grid[i][j] > 0)
            {
              matrix[i][j].first = max(matrix[i-1][j].first,matrix[i][j-1].first) * grid[i][j];
              matrix[i][j].second = min(matrix[i-1][j].second,matrix[i][j-1].second) * grid[i][j];
            }
            else
            {
              matrix[i][j].second = max(matrix[i-1][j].first,matrix[i][j-1].first) * grid[i][j];
              matrix[i][j].first = min(matrix[i-1][j].second,matrix[i][j-1].second) * grid[i][j];
            }
          }
        }
      return (matrix[m-1][n-1].first >= 0) ? matrix[m-1][n-1].first%MOD : -1;
    }
};