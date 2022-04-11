class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
      vector<int> temp;
      for (int i = 0; i < grid.size(); i++)
        {
          for (int j = 0; j < grid[0].size(); j++)
            temp.push_back(grid[i][j]);
        }
      
      int m = grid.size()*grid[0].size();
      k = m - k%m;
      for (int i = 0; i < grid.size(); i++)
        {
          for (int j = 0; j < grid[0].size(); j++)
            grid[i][j] = temp[(k++)%m];
        }
      return grid;
    }
};