class Solution {
  vector<int> colour;
  
  bool do_BFS(int i, int c,vector<vector<int>> graph)
  {
    colour[i] = c;
    queue<int> q;
    q.push(i);
    
    while (!q.empty())
    {
//       for (int i = 0 ; i < colour.size(); i++)
//         cout << colour[i] << "    ";
      
      // cout << endl;
      
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
  
public:
    bool isBipartite(vector<vector<int>>& graph) {
        colour = vector<int>(graph.size(),-1);
      
      for (int i = 0 ; i < graph.size(); i++)
      {
        if (colour[i] == -1)
        {
          if (!do_BFS(i,0,graph))
            return false;
        }
      }
      return true;
    }
};