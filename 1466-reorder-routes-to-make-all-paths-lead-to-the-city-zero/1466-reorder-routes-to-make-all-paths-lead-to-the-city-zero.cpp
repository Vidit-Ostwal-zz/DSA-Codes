class Solution {
  unordered_map<int,vector<pair<int,bool>>> mapofedges;

void make_map (vector<vector<int>> &B)
{
    for (int i = 0; i < B.size(); i++)
    {
        mapofedges[B[i][0]].push_back(make_pair(B[i][1],true));
        mapofedges[B[i][1]].push_back(make_pair(B[i][0],false));
    }
}
public:
    int minReorder(int n, vector<vector<int>>& connections) {
      
      make_map(connections);
      vector<bool> canvisited(n,true);
      
      queue<int> pq;
      pq.push(0);
      canvisited[0] = false;
      int changed_roads = 0;
      
      while (!pq.empty())
      {
        int curr_node = pq.front();
        pq.pop();
        
        for (int i = 0; i < mapofedges[curr_node].size(); i++)
        {
          int next_node = mapofedges[curr_node][i].first;
          bool IsRoad = mapofedges[curr_node][i].second;
          
          
          if (canvisited[next_node])
          {
            canvisited[next_node] = false;
            
            if (IsRoad)
              changed_roads++;
            
            pq.push(next_node);
          }
        }
      }
      return changed_roads;
    }
};