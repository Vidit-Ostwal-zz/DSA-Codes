class Solution {
  vector<bool> visited;
  vector<bool> answer;
  
  bool runDFS (int node,vector<vector<int>>&graph)
  {
    // Memoization Case
    if (!visited[node])
      return answer[node];
    
    visited[node] = false;
    
    if (graph[node].size() == 0)
      return answer[node] =  true;
    
    bool flag = true;
    for (int i = 0; i < graph[node].size(); i++)
    {
      int next_node = graph[node][i];
      flag = flag && runDFS(next_node, graph);
    }
    return answer[node] = flag;
  }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
      // N represent the number of nodes;
      int N = graph.size();
      visited = vector<bool>(N,true);
      answer = vector<bool>(N,false);
      
      for (int i = 0; i < N; i++)
      {
        if (visited[i])
          runDFS(i,graph);
      }
      
      vector<int> safenode;
      
      for (int i = 0; i < N; i++)
      {
        if (answer[i])
          safenode.push_back(i);
      }
      return safenode;
    }
};