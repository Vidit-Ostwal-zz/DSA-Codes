class Solution {
  int index = 0;
  map<string,int> u1;
  vector<int> parent;
  vector<int> rank;
  vector<double> value;
  vector<double> answer;
  
  void create_map_and_initialize (vector<vector<string>> equations)
  {
    for (int i = 0; i < equations.size(); i++)
    {
      if (u1.find(equations[i][0]) == u1.end())
        u1[equations[i][0]] = index++;
      
      if (u1.find(equations[i][1]) == u1.end())
        u1[equations[i][1]] = index++;
    }
    
    parent = vector<int>(index);
    rank = vector<int>(index,0);
    value = vector<double>(index,(double)INT_MAX);
    
    for (int i = 0; i < parent.size(); i++)
      parent[i] = i;
  }
  
  int find_parent(int i)
  {
    if (parent[i] == i)
      return i;
    
    return parent[i] = find_parent(parent[i]);
  }
  
  void union_by_rank(int i, int j, double fact)
  {
    int m = i;
    int n = j;
    
    int prev_parent = parent[n];
    i = find_parent(i);
    j = find_parent(j);
    
    if (rank[i] > rank[j])
      parent[j] = i;
    else if (rank[i] < rank[j])
      parent[i] = j;
    else
    {
      parent[j] = i;
      rank[i]++;
    }
    
    if (value[m] == INT_MAX && value[n] == INT_MAX)
    {
      value[m] = (double)1;
      value[n] = (double)1/fact;
    }
    else if (value[m] == INT_MAX)
      value[m] = value[n]*fact;
    else if (value[n] == INT_MAX) 
      value[n] = value[m]/fact;
    else
    {
     
      double temp = value[prev_parent]/value[n];
      value[n] = value[m]/fact;
      value[prev_parent] = temp*value[n];
      
      for (int k = 0; k < parent.size(); k++)
        if (parent[k] == prev_parent)
        {
          value[k] = value[k]*value[prev_parent];
          find_parent(k);
        }
    }
    
//      for (int i = 0; i < parent.size(); i++)
//         cout << parent[i] << " " << value[i] << "    ";
//      cout << endl;
//   }
  }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      
      create_map_and_initialize(equations);
//       cout << "Help" << endl;
      
      for (int i = 0; i < equations.size(); i++)
        union_by_rank(u1[equations[i][0]],u1[equations[i][1]],values[i]);
      
      // auto it = u1.begin();
      // while (it != u1.end())
      // {
      //   cout << it -> first << "    " << it->second << endl;
      //   it++;
      // }
      
//       for (int i = 0; i < parent.size(); i++)
//         cout << parent[i] << "    " << value[i] << endl;
        
      for (int i = 0; i < queries.size(); i++)
      {
        string s1 = queries[i][0];
        string s2 = queries[i][1];
        
        if (u1.find(s1) == u1.end() || u1.find(s2) == u1.end())
          answer.push_back((double)-1);
        else
        {
          int m = find_parent(u1[s1]);
          int n = find_parent(u1[s2]);
          
          if (m != n)
            answer.push_back((double)-1);
          else
            answer.push_back(value[u1[s1]]/value[u1[s2]]);
        }
      }
      return answer;
    }
};