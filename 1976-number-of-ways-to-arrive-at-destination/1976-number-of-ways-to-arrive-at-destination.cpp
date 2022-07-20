#define ll long long
#define pi pair<ll,ll>
const int mod = pow(10,9)+7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
      vector<pi> adj[n];
      
      for (auto &it : roads)
      {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
      }
      
      priority_queue<pi,vector<pi>,greater<pi>> pq;
      // Stores the minimum distance to reach from the source to this node
      
      
      vector<ll> min_dis(n,LONG_MAX);
      vector<ll> ways (n,0);
      
      // distance, node
      pq.push({0,0});
      min_dis[0] = 0;
      ways[0] = 1;
      
      while (!pq.empty())
      {
        ll node = pq.top().second;
        ll dist = pq.top().first;
        pq.pop();
        
        for (auto &it: adj[node])
        {
          ll nextNode = it.first;
          ll nextDist = it.second;
          
          if (dist + nextDist < min_dis[nextNode])
          {
            ways[nextNode] = ways[node];
            min_dis[nextNode] = dist + nextDist;
            pq.push({min_dis[nextNode],nextNode});
          }
          else if (dist + nextDist == min_dis[nextNode])
          {
             ways[nextNode] += ways[node];
            ways[nextNode] %= mod;
          }
        }
      }
      
      return ways[n-1]%mod;
    }
};