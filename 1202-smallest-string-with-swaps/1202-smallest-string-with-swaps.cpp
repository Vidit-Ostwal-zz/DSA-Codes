class Solution {
  vector<int> parent;
  vector<int> rank;
  
  /*Path Compression*/
  int find_parent(int i)
  {
    if (i == parent[i])
      return i;
    return parent[i] = find_parent(parent[i]);
  }
  
  void union_by_rank(int u, int v)
  {
//     int u1 = u;
//     int v1 = v;
//     cout << parent[u1] << "    " << parent[v1] << endl;
    
    u = find_parent(u);
    v = find_parent(v);
    
//      if (u1 == 10 && v1 == 11)
//        cout << rank[u] << "    " << rank[v1] << endl;
    
    if (u == v)
      return;
    
    if (rank[u] < rank[v])
      parent[u] = v;
    else if (rank[u] > rank[v])
      parent[v] = u;
    else
    {
      parent[v] = u;
      rank[u]++;
    }
    // cout << parent[u1] << "    " << parent[v1] << endl;
  }
  
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      unordered_map<int,string> u1;
      unordered_map<int,vector<int>> u2;
      parent = vector<int>(s.length());
      rank = vector<int>(s.length());
      
      for (int i = 0; i < s.length(); i++)
      {
        parent[i] = i;
        rank[i] = 0;
      }
      // cout << "Help" << endl;
      /*Through this all the things are paired into group*/ 
      for (int i = 0; i < pairs.size() ; i++)
        if (pairs[i][0] != pairs[i][1])
          union_by_rank(pairs[i][0],pairs[i][1]);
      
//       for (int i = 0; i < parent.size(); i++)
//         cout << parent[i] <<  "    " ;
      
      // cout << endl;
      for (int i = 0; i < parent.size(); i++)
        find_parent(i);
      
//       for (int i = 0; i < parent.size(); i++)
//         cout << parent[i] <<  "    " ;
//        cout << endl;
      
      for (int i = 0; i < parent.size(); i++)
      {
        u1[parent[i]] += s[i];
        u2[parent[i]].push_back(i);
      }
      
      auto it = u1.begin();
      
      while (it != u1.end())
      {
        sort(it->second.begin(),it->second.end());
        // cout << it->first << "     " << it->second << endl;
        it++;
      }
      
      it = u1.begin();
      while (it != u1.end())
      {
        int par = it->first;
        string temp = it->second;
        
        for (int i = 0; i < u2[par].size(); i++)
          s[u2[par][i]] = temp[i];
        
        it++;
      }
      return s;
    }
};