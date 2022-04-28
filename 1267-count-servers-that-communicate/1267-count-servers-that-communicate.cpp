class Solution {
  int Approach1(vector<vector<int>>grid)
  {
    int count = 0;
    int is_count = 0;
    unordered_map<int,vector<int>> u1;
    unordered_map<int,vector<int>> u2;
    
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j])
        {
          count++;
          u1[i].push_back(j);
          u2[j].push_back(i);
        }
      }
    
    auto it = u1.begin();
    while (it != u1.end())
    {
      if (it->second.size() == 1 && u2[it->second[0]].size() == 1)
        is_count++;
      
      it++;
    }
    return count - is_count;
  }
public:
    int countServers(vector<vector<int>>& grid) {
        return Approach1(grid);
    }
};