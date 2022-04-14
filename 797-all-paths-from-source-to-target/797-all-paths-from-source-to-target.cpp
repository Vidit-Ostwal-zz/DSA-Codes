class Solution {
  vector<vector<int>> answer;
  // unordered_map<int,vector<int>> u1;
  
  void BFS (vector<vector<int>> graph)
  {
    // vector<bool> visited(graph.size(),true);
    queue<pair<int,vector<int>>> q;
    
    vector<int> temp;
    temp.push_back(0);
    q.push(make_pair(0,temp));
    // visited[0] = false;
    while (!q.empty())
    {
      auto it = q.front();
      q.pop();
      
      int i = it.first;
      
      if (i == graph.size()-1)
        answer.push_back(it.second);
      
      for (int j = 0; j < graph[i].size(); j++)
      {
          it.second.push_back(graph[i][j]);
          q.push(make_pair(graph[i][j],it.second));
          it.second.pop_back();
      }
    }
  }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      // make_map (graph);
      BFS(graph);
      return answer;
    }
};