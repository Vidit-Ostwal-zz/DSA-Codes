class Solution {
  unordered_map<int,vector<int>> hash_map;
  vector<int> indegree;
  
  /*Makes the adjancy List for the Graph*/
  void make_adjancy_list(vector<vector<int>> pre)
  {
    for (int i = 0; i < pre.size(); i++)
      hash_map[pre[i][1]].push_back(pre[i][0]);
  }
  
  /*Make indegree Vector*/
  void make_ID(vector<vector<int>> pre, int numCourses)
  {
    indegree = vector<int>(numCourses,0);
    
    for (int i = 0; i < pre.size(); i++)
      indegree[pre[i][0]]++;
  }
  
  /*Check Cycle via DFS Traversal*/
  bool check_cycle_DFS(int index, vector<bool>&vis, vector<bool>&temp_vis)
  {
    vis[index] = false;
    temp_vis[index] = false;
    
    for (int i = 0; i < hash_map[index].size(); i++)
    {
      if (vis[hash_map[index][i]])
      {
        if (check_cycle_DFS(hash_map[index][i],vis,temp_vis))
          return true;
      }
      else
      {
        if (!temp_vis[hash_map[index][i]])
          return true;
      }
    }
    temp_vis[index] = true;
    return  false;
  }
  
  /*Check Cycle via BFS Traversal Topological Sorting Length*/
  bool make_topo (int N)
  {
    vector<int> topo_sort;
    
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
      if (indegree[i] == 0)
        q.push(i);
    
    while (!q.empty())
    {
      int temp = q.front();
      q.pop();
      topo_sort.push_back(temp);
      
      for (int i = 0; i < hash_map[temp].size(); i++)
      {
        indegree[hash_map[temp][i]]--;
        if (indegree[hash_map[temp][i]] == 0)
          q.push(hash_map[temp][i]);
      }
    }
    return (N == topo_sort.size());
  }

  
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        make_adjancy_list(prerequisites);
      make_ID(prerequisites,numCourses);
      /*DFS*/
      /*
      vector<bool> vis(numCourses,true);
      vector<bool> temp_vis(numCourses,true);
      for (int i = 0; i < vis.size(); i++)
      {
        
        if (vis[i])
        {
          if (check_cycle_DFS(i,vis,temp_vis))
            return false;
        }
      }
      return true;
      */
      
      return make_topo(numCourses);
    }
};