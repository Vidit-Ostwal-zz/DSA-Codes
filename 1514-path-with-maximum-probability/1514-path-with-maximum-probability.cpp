#define ld long double
#define pi pair<ld,int>
const int mod = pow(10,9)+7;


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pi> adj[n];
      
      for (int i = 0; i < edges.size(); i++)
      {
        int src1 = edges[i][0];
        int src2 = edges[i][1];
        
        adj[src1].push_back({succProb[i],src2});
        adj[src2].push_back({succProb[i],src1});
      }
      
      priority_queue<pi> pq;
      // Stores the minimum distance to reach from the source to this node
      
      
      vector<ld> max_prob(n,0);
      
      // distance, node
      pq.push({1,start});
      max_prob[start] = 1;
      
      while (!pq.empty())
      {
        int node = pq.top().second;
        ld prob = pq.top().first;
        pq.pop();
        
        for (auto &it: adj[node])
        {
          int nextNode = it.second;
          ld nextProb = it.first;
          
          if (prob*nextProb > max_prob[nextNode])
          {
            max_prob[nextNode] = prob*nextProb;
            pq.push({max_prob[nextNode],nextNode});
          }
        }
      }
      
      return (double)max_prob[end];
    }
};