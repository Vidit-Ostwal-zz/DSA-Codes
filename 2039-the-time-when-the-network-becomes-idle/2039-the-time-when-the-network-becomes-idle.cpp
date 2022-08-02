class Solution {
  // We need to find out the shortest distance of the nodes from master node, Graph is like Undirected Graph, 
  // We Can use dikjstra's Algo, but we can use a simple BFS algo form the master node to find out the distance from the source node and 
  // destination node;
  
  vector<int> distance;
  void find_distance(vector<vector<int>> &B, int n)
  {
    unordered_map<int,vector<int>> mapofedges;
    distance = vector<int>(n,INT_MAX);
    
    for (int i = 0; i < B.size(); i++)
    {
        mapofedges[B[i][0]].push_back(B[i][1]);
        mapofedges[B[i][1]].push_back(B[i][0]);
    }
    
    distance[0] = 0;
    
    queue<int> next_node_queue;
    next_node_queue.push(0);
    
    int dis = 1;
    while (!next_node_queue.empty())
    {
      int size = next_node_queue.size();
      
      while (size)
      {
        int curr_node = next_node_queue.front();
        next_node_queue.pop();
        
        for (int i = 0; i < mapofedges[curr_node].size(); i++)
        {
          int next_node = mapofedges[curr_node][i];
          
          if (distance[next_node] > dis)
          {
            distance[next_node] = dis;
            next_node_queue.push(next_node);
          }
        }
        size--;
      }
      dis++;
    }
  }

public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
      
      int n = patience.size();
      int answer = -1;
      find_distance(edges,n);
      
      // show_vector(distance);
      for (int i = 1; i < n; i++)
      {
        int time_required = distance[i] * 2;
        int queries = ceil(time_required/(double)patience[i]);
        answer = max(answer,(queries-1)*patience[i] + time_required);
        // cout << queries << "   " << patience[i] << "   " << time_required << endl; 
        // cout << (queries-1)*patience[i] + time_required << endl;
        // cout << answer << endl;
      }
      return answer+1;
    }
};