class Solution {
  vector<int> colour;
  
  bool do_BFS(int i, int c,vector<vector<int>> graph)
  {
    colour[i] = c;
    queue<int> q;
    q.push(i);
    
    while (!q.empty())
    {
      int k = q.front();
      c = colour[k];
      q.pop();
      c = (c) ? 0 : 1;
      
      for (int j = 0; j < graph[k].size(); j++)
      {
        if (colour[graph[k][j]] == -1)
        {
          colour[graph[k][j]] = c;
          q.push(graph[k][j]);
        }
        else if (colour[graph[k][j]] != c)
          return false;
      }
    }
    return true;
  }
  
  bool do_DFS(int i, int c,vector<vector<int>> graph)
  {
    if (colour[i] == c)
      return true;
    
    if (colour[i] == -1)
      colour[i] = c;
    
    if (colour[i] != c)
      return false;
    
    c = (c) ? 0 : 1;
    
    bool flag = true;
    for (int j = 0; j < graph[i].size(); j++)
      flag = flag && do_DFS(graph[i][j],c,graph);
    
    return flag;
  }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        colour = vector<int>(graph.size(),-1);
      
      for (int i = 0 ; i < graph.size(); i++)
        if (colour[i] == -1)
          if (!do_BFS(i,0,graph))
            return false;
      
      return true;
    }
};