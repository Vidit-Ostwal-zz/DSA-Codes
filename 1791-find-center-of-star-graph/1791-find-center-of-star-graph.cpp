class Solution {
  unordered_map<int,vector<int>> u1;
  void make_tree (vector<vector<int>> edges)
  {
    for (int i = 0; i < edges.size(); i++)
    {
      u1[edges[i][0]].push_back(edges[i][1]);
      u1[edges[i][1]].push_back(edges[i][0]);
    }
  }
public:
    int findCenter(vector<vector<int>>& edges) {
        make_tree (edges);
      
      auto it = u1.begin();
      
      int answer = 0;
      int index = 0;
      while (it != u1.end())
      {
        if (answer < it->second.size())
        {
          answer = it -> second.size();
          index = it->first;
        }
        it++;
      }
      return index;
    }
};