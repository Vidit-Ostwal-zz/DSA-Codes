class DisjointSetUnion{
  int n;
  vector<int> parent;
  vector<int> rank;
  
  public:
  DisjointSetUnion(int size)
  {
    n = size;
    parent = vector<int>(n,0);
    rank = vector<int>(n,0);
    
    for (int i = 0; i < parent.size(); i++)
      parent[i] = i;
  }
  
  int get_parent(int n)
  {
    if (parent[n] == n)
      return n;
    return parent[n] = get_parent(parent[n]);
  }
  
  bool union_by_rank(int x, int y)
  {
    x = get_parent(x);
    y = get_parent(y);
    
    if (x == y)
      return false;
    else if (rank[x] > rank[y])
      parent[y] = x;
    else if (rank[y] > rank[x])
      parent[x] = y;
    else
    {
      parent[y] = x;
      rank[x]++;
    }
    return true;
  }
  
  int countcomponents()
  {
    set<int> parentset;
    for (int i = 0; i < parent.size(); i++)
      parentset.insert(get_parent(i));
    
    return parentset.size();
  }
};


class Solution {
  
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
      int cables = connections.size();
      
      if (cables < n-1)
        return -1;
      
      DisjointSetUnion DSG(n);
      
      for (int i = 0; i < connections.size(); i++)
        DSG.union_by_rank(connections[i][0],connections[i][1]);
      
      return DSG.countcomponents()-1;
    }
};