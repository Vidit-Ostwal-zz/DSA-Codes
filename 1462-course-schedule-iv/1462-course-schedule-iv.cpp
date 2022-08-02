class Solution {
  vector<unordered_map<int,int>> isprereq;
  vector<bool> Isvisited;
  unordered_map<int,vector<int>> mapofedges;
  
  void tryDFS(int node)
  {
    Isvisited[node] = true;
    
    for (int i = 0; i < mapofedges[node].size(); i++)
    {
      int next_node = mapofedges[node][i];

      if (!Isvisited[next_node])
        tryDFS(next_node);
      
      isprereq[node][next_node]++;
      auto it = isprereq[next_node].begin();
      
      while (it != isprereq[next_node].end())
      {
        isprereq[node][it -> first]++;
        it++;
      }
    }
  }
  
  
  void make_map (vector<vector<int>> &B)
  {
    for (int i = 0; i < B.size(); i++)
        mapofedges[B[i][0]].push_back(B[i][1]);
  }
  
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
      isprereq = vector<unordered_map<int,int>>(numCourses);
      Isvisited = vector<bool>(numCourses,false);
      make_map(prerequisites);
      
      for (int i = 0; i < numCourses; i++)
      {
        if (!Isvisited[i])
          tryDFS(i);
      }
      
      vector<bool> query;
      
      for (int i = 0; i < queries.size(); i++)
      {
        int Parent = queries[i][0];
        int Child = queries[i][1];
        
        if (isprereq[Parent][Child])
          query.push_back(true);
        else
          query.push_back(false);
      }
      return query;
    }
};