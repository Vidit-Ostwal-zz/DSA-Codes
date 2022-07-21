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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
      
      DisjointSetUnion DSU(n);
      
      for (int i = 0; i < isConnected.size(); i++)
      {
        for (int j = 0; j < isConnected[0].size(); j++)
        {
          if (isConnected[i][j] && i != j)
            DSU.union_by_rank(i,j);
        }
      }
      
      return DSU.countcomponents();
    }
};