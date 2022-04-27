class Solution {
  vector<int> parent;
  vector<int> rank;
  
  int find_parent(int i)
  {
    if (i == parent[i])
      return i;
    return parent[i] = find_parent(parent[i]);
  }
  
  
  void union_by_rank(int u, int v)
  {   
    u = find_parent(u);
    v = find_parent(v);
    
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
  }
  
public:
    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& pairs)
    {   
      unordered_map<int,vector<int>> u2;
      parent = vector<int>(s.size());
      rank = vector<int>(s.size());
      vector<int> visited(s.size(),true);
      int answer = 0;
      
      for (int i = 0; i < s.size(); i++)
      {
        parent[i] = i;
        rank[i] = 0;
      }
      
      for (int i = 0; i < pairs.size() ; i++)
        if (pairs[i][0] != pairs[i][1])
          union_by_rank(pairs[i][0],pairs[i][1]);
      
       for (int i = 0; i < parent.size(); i++)
         find_parent(i);
      
      for (int i = 0; i < parent.size(); i++)
        cout << parent[i] << "   " ;
      cout << endl;
      for (int i = 0; i < parent.size(); i++)
        u2[parent[i]].push_back(i);
      
      auto it = u2.begin();
      
      while (it != u2.end())
      {
        unordered_map<int,int> temp;
        
        for (int i = 0; i < it->second.size(); i++)
        {
          visited[it->second[i]] = false;
          temp[s[it->second[i]]]++;
           cout << temp.size() << " ";
          temp[t[it->second[i]]]--;
          
          if (temp.find(t[it->second[i]]) != temp.end() && temp[t[it->second[i]]] == 0)
            temp.erase(t[it->second[i]]);
          
          if (temp.find(s[it->second[i]]) != temp.end() && temp[s[it->second[i]]] == 0)
            temp.erase(s[it->second[i]]);
          
          cout << temp.size() << "    ";
        }
        
        auto it1 = temp.begin();
        
        while (it1 != temp.end())
        {
          answer += abs(it1->second);
          it1++;
        }
        it++;
      }
      
//       for (int i = 0; i < visited.size(); i++)
//         if (visited[i] && s[i] != t[i])
//           answer++;
      
      return answer/2;
    }
};