class Solution {
  int Floyyd_Warshall(int n, vector<vector<int>>&edges, int K)
  {
    // Works only for Directed graph
    // convert UnDirected Graph into Directed Graph
    
    
    // We need to change the dis vector with correct edges in edges
    // Also as there it's a undirected graph we will add to both the vertices and dis from a vertex to the same vertex is also zero
    vector<vector<int>> dis(n,vector<int>(n,INT_MAX/2));
    
    for (int i = 0; i < edges.size(); i++)
    {
      int sr = edges[i][0];
      int des = edges[i][1];
      int wgt = edges[i][2];
      
      dis[sr][des] = wgt;
      dis[des][sr] = wgt;
      // Made undirected to Directed
      // dis[sr][sr] = 0;
      // dis[des][des] = 0;
    }
    
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    
    int mincity = -1;
    int minCount = INT_MAX;
    
    for (int i = 0; i < dis.size(); i++)
    {
      int count = 0;
      for (int j = 0; j < dis[0].size(); j++)
      {
        if (i != j)
          if (dis[i][j] <= K)
            count++;
      }
      if (count <= minCount)
      {
        minCount = count;
        mincity = i;
      }
    }
    return mincity;
  }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        return Floyyd_Warshall(n,edges,distanceThreshold);
    }
};