class Solution {
  /*Prism Algorithm*/ 
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      
      if (points.size() <= 1 )
        return 0;
      
        unordered_map<int,vector<pair<int,int>>> u1;
      
      for (int i = 0; i < points.size(); i++)
      {
        for (int j = i + 1; j < points.size() ; j++)
        {
          int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
          u1[i].push_back(make_pair(dis,j));
          u1[j].push_back(make_pair(dis,i));
        }
      }
      
      int n = points.size() - 1;
      vector<bool> visited(points.size() - 1,true);
      
      visited[0] = false;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
      
      for (int j = 0; j < u1[0].size(); j++)
        pq.push(u1[0][j]);
      
      int sum = 0;
      
      while (n)
      {
        auto it = pq.top();
        pq.pop();
        
        if (visited[it.second])
        {
           sum += it.first;
           visited[it.second] = false;
          
          for (int j = 0; j < u1[it.second].size(); j++)
            if (visited[u1[it.second][j].second])
              pq.push(u1[it.second][j]);
          n--;
        }
      }
      return sum;
    }
};