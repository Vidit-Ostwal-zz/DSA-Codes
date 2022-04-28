class Solution {
  vector<int> parent;
  vector<int> rank;
  
  int find_parent(int i)
  {
    if (parent[i] == i)
      return i;
    
    return parent[i] = find_parent(parent[i]);
  }
  
  void rank_by_union(int x, int y)
  {
    x = find_parent(x);
    y = find_parent(y);
    
    if (x == y)
      return;
    
    if (rank[x] > rank[y])
      parent[y] = x;
    else if (rank[x] < rank[y])
      parent[x] = y;
    else
    {
      parent[y] = x;
      rank[x]++;
    }
  }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      unordered_map<int,vector<int>> u1;
      
      for (int i=  0; i < isConnected[0].size(); i++)
      {
        parent.push_back(i);
        rank.push_back(0);
      }
      
      for (int i = 0; i < isConnected.size(); i++)
        for (int j = 0; j < isConnected[0].size(); j++)
          if (isConnected[i][j] && i != j)
            rank_by_union(i,j);
      
      for (int i = 0; i < parent.size(); i++)
      {
        parent[i] = find_parent(i);
        u1[parent[i]].push_back(i);
      }
      return u1.size();
    }
};