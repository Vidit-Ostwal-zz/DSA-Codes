class Solution {
  int answer = -1;
  int time = 1;
  
  vector<int> distance;
  vector<bool> visited;
  
  void try_dfs(vector<int>&edges, int curr_node,vector<bool>&B)
  {
    visited[curr_node] = false;
    distance[curr_node] = time++;
    B[curr_node] = false;
    
    int next_node = edges[curr_node];
    
    if (next_node == -1)
    {
      B[curr_node] = true;
      return;
    }
    
    if (visited[next_node])
      try_dfs(edges,next_node,B);
    else
    {
      if (!B[next_node])
        answer = max(answer,abs(distance[next_node] - distance[curr_node]) + 1);
    }
    B[curr_node] = true;
  }
public:
    int longestCycle(vector<int>& edges) {
        
      distance = vector<int>(edges.size(),-1);
      visited = vector<bool>(edges.size(),true);
      vector<bool> pathVisited(edges.size(),true);
      
      for (int i = 0; i < edges.size(); i++)
      {
        if (visited[i])
          try_dfs(edges,i,pathVisited);
      }
      return answer;
    }
};