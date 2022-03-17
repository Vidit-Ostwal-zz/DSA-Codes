class Solution {
  unordered_map<int,vector<int>> hash_map;
  
  /*Makes the adjancy List for the Graph*/
  void make_adjancy_list(vector<vector<int>> pre)
  {
    for (int i = 0; i < pre.size(); i++)
      hash_map[pre[i][1]].push_back(pre[i][0]);
  }
  
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
  
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        make_adjancy_list(prerequisites);
      
      vector<bool> vis(numCourses,true);
      vector<bool> temp_vis(numCourses,true);
      for (int i = 0; i < vis.size(); i++)
      {
        /*Not Yet Visited*/
        if (vis[i])
        {
          if (check_cycle_DFS(i,vis,temp_vis))
            return false;
        }
      }
      return true;
    }
};