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
      unordered_map<int,int> u2;
      
      u2[edges[0][1]]++;
      u2[edges[0][0]]++;
      u2[edges[1][1]]++;
      u2[edges[1][0]]++;
      
      auto it = u2.begin();
      
      while (it != u2.end())
      {
        if( it -> second > 1)
          return it -> first;
        it++;
      }
      return -2;
        // make_tree (edges);
      
//       auto it = u1.begin();
      
//       int answer = 0;
//       int index = 0;
//       while (it != u1.end())
//       {
//         if (answer < it->second.size())
//         {
//           answer = it -> second.size();
//           index = it->first;
//         }
//         it++;
//       }
//       return index;
    }
};