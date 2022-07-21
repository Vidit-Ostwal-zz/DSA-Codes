class Solution {
  #define pi pair<int,int>
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      
      vector<int> adj[n];
      
      for (int i = 0; i < manager.size(); i++)
      {
        if (i != headID)
          adj[manager[i]].push_back(i);
      }
      
      vector<int> min_time(n,INT_MAX);
      priority_queue<pi,vector<pi>,greater<pi>> pq;
      min_time[headID] = 0;
      pq.push(make_pair(0,headID));
      
      
      while (!pq.empty())
      {
        int time = pq.top().first;
        int node = pq.top().second;
        
        pq.pop();
        
        for (int i = 0; i < adj[node].size(); i++)
        {
          int nexttime = informTime[node];
          int nextNode = adj[node][i];
          
          if (nexttime + time < min_time[nextNode])
          {
            min_time[nextNode] = nexttime + time;
            pq.push(make_pair(min_time[nextNode],nextNode));
          }
        }
      }
      
      int max_time = -1;
      for (auto &num : min_time)
        max_time = max(max_time,num);
      
      return max_time;
    }
};