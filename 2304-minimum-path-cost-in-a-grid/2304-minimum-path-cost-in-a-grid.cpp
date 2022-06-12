class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
      vector<vector<int>> GRID(grid.begin(),grid.end());
      
        int answer = INT_MAX;
      for (int i = 1; i < grid.size(); i++)
      {
        for (int j = 0; j < grid[0].size(); j++)
        {
          int row = i-1;
          int temp_cost = INT_MAX;
          for (int k = 0; k < grid[0].size(); k++)
          {
            int temp_cost1 = 0;
            int value = GRID[row][k];
            temp_cost1 += grid[row][k];
            temp_cost1 += moveCost[value][j];
            
            
            temp_cost = min(temp_cost,temp_cost1);
          }
          grid[i][j] += temp_cost;
          
          if (i == grid.size()-1)
          {
            answer = min(answer,grid[i][j]);
          }
        }
      }
      return answer;
    }
};