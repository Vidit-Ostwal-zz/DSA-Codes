class Solution {
  vector<map<int,int>> ancestors;
  vector<int> indegree;
  
  unordered_map<int,vector<int>> mapofedges;
  
  void make_map (vector<vector<int>> &B)
  {
    for (int i = 0; i < B.size(); i++)
    {
      mapofedges[B[i][0]].push_back(B[i][1]);
      indegree[B[i][1]]++;
    }
}
  
  void tryBFS()
  {
    queue<int> node;
  
    for (int i = 0; i < indegree.size(); i++)
    {
      if (!indegree[i])
        node.push(i);
    }
    
    while (!node.empty())
    {
      int curr_node = node.front();
      node.pop();
      
      for (int i = 0; i < mapofedges[curr_node].size(); i++)
      {
        int next_node = mapofedges[curr_node][i];
        
        indegree[next_node]--;
        ancestors[next_node][curr_node]++;
        
        auto it = ancestors[curr_node].begin();
        while (it != ancestors[curr_node].end())
        {
          ancestors[next_node][it -> first]++;
          it++;
        }
        
        if (!indegree[next_node])
          node.push(next_node);
      }
    }
  }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
      // Initialization
      ancestors = vector<map<int,int>>(n);
      indegree = vector<int>(n,0);
      make_map(edges);
      
      tryBFS();
      
      vector<vector<int>> Ancestors(n);
      
      for (int i = 0; i < n; i++)
      {
        auto it = ancestors[i].begin();
        
        while (it != ancestors[i].end())
        {
          Ancestors[i].push_back(it -> first);
          it++;
        }
      }
      return Ancestors;
    }
};