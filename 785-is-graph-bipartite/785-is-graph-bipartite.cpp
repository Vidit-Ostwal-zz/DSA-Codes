class Solution
{
  vector<int> color;
  
  bool doDFS (vector<vector<int>> & graph,int index, int c)
  {
    if (color[index] != -1)
    {
      // Node already visited
      if (color[index] == c)
        return true;
      else
        return false;
    }
    
    color[index] = c;
    c = !c;
    
    bool flag = true;
    
    for (int i = 0; i < graph[index].size(); i++)
      flag = flag && doDFS(graph,graph[index][i],c);
    
    return flag;
  }
  
    public:
        bool isBipartite(vector<vector < int>> &graph) {
        
          int N = graph.size();
          color = vector<int>(N,-1);
          
          bool flag = true;
          
          for (int i = 0; i < N; i++)
          {
            if (color[i] == -1)
            {
              // Node Yet not visited
              flag = flag && doDFS(graph,i,1);
            }
          }
          
          return flag;
        }
};