class Solution {
  /*Get Adjacency Matrix*/
  unordered_map<int,vector<int>> get_adjacency_matrix(vector<vector<int>> temp)
  {
    unordered_map<int,vector<int>> hash_map;
    
    /*Undirected Graph*/
    for (int i = 0; i < temp.size(); i++)
    {
      hash_map[temp[i][0]].push_back(temp[i][1]);
      hash_map[temp[i][1]].push_back(temp[i][0]);
    }
    return hash_map;
  }
  
  /*Will return if it is possible to colour with the given condition*/
  /*Time Complexity = O(N) + O(E)
  Space Complexity = O(N)*/
  bool check_DFS(int index, vector<int>&color,unordered_map<int,vector<int>> hash_map, int flag)
  {
    color[index] = flag;
    flag = (flag) ? 0 : 1;
    
    for (int i = 0; i < hash_map[index].size(); i++)
    {
      if (color[hash_map[index][i]] == -1)
      {
        if (!check_DFS(hash_map[index][i],color,hash_map, flag))
          return false;
      }
      else
        if (color[hash_map[index][i]] != flag)
          return false;
    }
    return true;
  }
  
  bool check_via_DFS(int n, unordered_map<int,vector<int>> hash_map)
  {
    vector<int> color(n+1,-1);
    
    for (int i = 1; i < color.size(); i++)
    {
      /*This will only hit when there are disconnected componenets in a Graph*/
      if (color[i] == -1)
      {
        /*Disconnected Components for the first node we can throw flag 0, directly no problem with that*/
        if (!check_DFS(i,color,hash_map,0))
          return false;
      }
    }
    return true;
  }
  
  bool check_via_BFS(int n, unordered_map<int,vector<int>> hash_map)
  {
    /*Used as visited Vector*/
    vector<int> colour (n+1,-1);
    int flag = 0;
    
    for (int i = 1; i < colour.size(); i++)
    {
      /*Not Yet Visiited 
      Case of Disconnected Graph*/
      if (colour[i] == -1)
      {
        queue<int> q;
        q.push(i);
        colour[i] = flag;
        
        while (!q.empty())
        {
          flag = (flag) ? 0: 1;
          int size = q.size();
          
          while (size > 0)
          {
            int temp = q.front();
            q.pop();
            
            for (int i = 0; i < hash_map[temp].size(); i++)
            {
              if (colour[hash_map[temp][i]] == -1)
              {
                colour[hash_map[temp][i]] = flag;
                q.push(hash_map[temp][i]);
              }
              else
              {
                if (colour[hash_map[temp][i]] != flag)
                  return false;
              }
              
            }
            size--;
          }
        }
      }
    }
    return true;
  }
  
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> hash_map = get_adjacency_matrix(dislikes);
      
      // return check_via_DFS(n,hash_map);
      
      return check_via_BFS(n,hash_map);
    }
};