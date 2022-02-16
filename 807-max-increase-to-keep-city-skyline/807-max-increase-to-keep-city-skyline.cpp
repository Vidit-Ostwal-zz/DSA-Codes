class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
      vector<int> hori(grid.size(),-1);
      vector<int> vert(grid.size(),-1);
      
      for (int i =0; i < grid.size(); i++)
      {
        for (int j = 0; j < grid[0].size(); j++)
        {
          hori[j] = max(hori[j],grid[i][j]);
          vert[i] = max(vert[i],grid[i][j]);
        }
      }
      
      int answer = 0;
      for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
        {
          int mini = min(hori[j],vert[i]);
          answer += abs(grid[i][j] - mini);
        }
      return answer;
    }
};