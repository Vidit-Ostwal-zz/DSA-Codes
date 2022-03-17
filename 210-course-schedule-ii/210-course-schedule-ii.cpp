class Solution {
  unordered_map<int,vector<int>> hash_map;
  vector<int> indegree;
  
  /*Makes the Adjancy List of the prerequisites*/
  void make_adjancy(vector<vector<int>> pre)
  {
    for (int i = 0; i < pre.size(); i++)
      hash_map[pre[i][1]].push_back(pre[i][0]);
  }
  
  /*Make the indegree vector for the pre requisited*/
  void make_indegree(vector<vector<int>> pre, int num)
  {
    indegree = vector<int>(num,0);
    for (int i = 0; i < pre.size(); i++)
      indegree[pre[i][0]]++;
  }

  vector<int> make_topo(int num)
  {
    vector<int> topo;
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }
    
    while (!q.empty())
    {
      int temp = q.front();
      topo.push_back(temp);
      q.pop();
      
      for (int i = 0; i < hash_map[temp].size(); i++)
      {
        indegree[hash_map[temp][i]]--;
        if (indegree[hash_map[temp][i]] == 0)
          q.push(hash_map[temp][i]);
      }
    }
    vector<int> t;
    return (topo.size() == num) ? topo : t; 
  }
  
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        make_adjancy(prerequisites);
      make_indegree(prerequisites,numCourses);
      
      return make_topo(numCourses);
    }
};