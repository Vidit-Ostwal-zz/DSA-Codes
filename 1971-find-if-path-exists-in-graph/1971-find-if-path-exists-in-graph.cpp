class Solution {
  vector<vector<int>> ad_list;
  void get_adjancey (int n, vector<vector<int>>& edges)
  {
    ad_list = vector<vector<int>>(n);
    for (int i = 0; i < edges.size(); i++)
    {
      ad_list[edges[i][0]].push_back(edges[i][1]);
      ad_list[edges[i][1]].push_back(edges[i][0]);
    }
  }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      /*Visited Vector*/
      vector<bool> vis(n,true);
      get_adjancey(n,edges);
      
      queue<int> q;
      q.push(source);
      vis[source] = false;
      
      if (source == destination)
        return true;
      
      while(!q.empty())
      {
        int index = q.front(); 
        q.pop();
        
        for (int j = 0; j < ad_list[index].size(); j++)
        {
          if (vis[ad_list[index][j]])
          {
            vis[ad_list[index][j]] = false;
            if (ad_list[index][j] == destination)
              return true;
            
            q.push(ad_list[index][j]);
          }
        }
      }
      
      return false;
    }
};