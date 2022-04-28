class Solution {
  vector<vector<pair<int,int>>> parent;
  vector<vector<int>> rank;
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
  
  pair<int,int> find_parent(int i, int j)
  {
    if (parent[i][j].first == i && parent[i][j].second == j)
      return parent[i][j];
    
    auto it = find_parent(parent[i][j].first,parent[i][j].second);
    parent[i][j].first = it.first;
    parent[i][j].second = it.second;
    return parent[i][j];
  }
  
  void union_by_rank(int x1, int y1, int x2, int y2)
  {
    auto it = find_parent(x1,y1);
    x1 = it.first;
    y1 = it.second;
    
    it = find_parent(x2,y2);
    x2 = it.first;
    y2 = it.second;
    
    if (x1 == x2 && y1 == y2)
      return;
    
    if (rank[x1][y1] > rank[x2][y2])
    {
      parent[x2][y2].first = x1;
      parent[x2][y2].second = y1;
    }
    else if (rank[x1][y1] < rank[x2][y2])
    {
      parent[x1][y1].first = x2;
      parent[x1][y1].second = y2;
    }
    else
    {
      parent[x2][y2].first = x1;
      parent[x2][y2].second = y1;
      rank[x1][y1]++;
    }
  }
  
public:
    int countServers(vector<vector<int>>& grid) {
        // return Approach1(grid);
      
      /*Now these both will keep track of component connected via rows and column seperately*/
      unordered_map<int,vector<int>> u1;
      unordered_map<int,vector<int>> u2;
      parent = vector<vector<pair<int,int>>>(grid.size(),vector<pair<int,int>>(grid[0].size()));
      rank = vector<vector<int>>(grid.size(),vector<int>(grid[0].size()));
      unordered_map<int,int> count_map;
      int count = 0;
      
      for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
        {
          if (grid[i][j])
          {
            parent[i][j] = make_pair(i,j);
            rank[i][j] = 0;
            u1[i].push_back(j);
            u2[j].push_back(i);
          }
        }
      
      auto it = u1.begin();
      
      while (it != u1.end())
      {
        int row = it->first;
        vector<int> temp = it->second;
        
        for (int i = 0; i < temp.size(); i++)
          union_by_rank(row,temp[0],row,temp[i]);
        
        it++;
      }
      
      it = u2.begin();
      while (it != u2.end())
      {
        int col = it->first;
        vector<int> temp = it->second;
        
        for (int i = 0; i < temp.size(); i++)
          union_by_rank(temp[0],col,temp[i],col);
        
        it++;
      }
      
      for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
          if (grid[i][j])
          {
            auto it = find_parent(i,j);
            parent[i][j].first = it.first;
            parent[i][j].second = it.second;
            count_map[it.first]++;
          }
      
      
      auto it1 = count_map.begin();
      
      while (it1 != count_map.end())
      {
        if ( it1->second != 1)
          count += it1->second;
        
        it1++;
      }
      return count;
    }
};