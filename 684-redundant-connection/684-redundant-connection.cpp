class Solution {
  vector<int> rank;
  vector<int> parent;
  
  int find_parent (int i)
  {
    if (parent[i] == i)
      return i;
    
    return parent[i] = find_parent(parent[i]);
  }
  
  
  bool union_by_rank(int i, int j)
  {
    i = find_parent(i);
    j = find_parent(j);
    
    if (i == j)
      return true;
    
    if (rank[i] > rank[j])
      parent[j] = i;
    else if (rank[i] < rank[j])
      parent[i] = j;
    else
    {
      parent[j] = i;
      rank[i]++;
    }
    return false;
  }
  
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
      
      // Basic Initialization 
      for (int i = 0; i <= n; i++)
      {
        rank.push_back(0);
        parent.push_back(i);
      }
      
      for (int i = 0; i <= n ;i++)
        find_parent(i);
      
      for (int i = 0; i < n; i++)
      {
        int x = edges[i][0];
        int y = edges[i][1];
        
        if (union_by_rank(x,y))
          return edges[i];
      }
      return {};
    }
};