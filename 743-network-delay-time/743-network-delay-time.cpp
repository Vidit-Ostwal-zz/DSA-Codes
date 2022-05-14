/*
class Solution {
  unordered_map<int,vector<vector<int>>> u1;
  unordered_map<int,int> MST_vertex;
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
  vector<int>time;
  int maxi = INT_MIN;
  
  void make_adjlist(vector<vector<int>> times)
  {
    for (int i = 0; i < times.size(); i++)
    {
      int src = times[i][0];
      u1[src].push_back(times[i]);
    }
  }
  
  
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      
      make_adjlist(times);
      time = vector<int>(n,0);
      
      MST_vertex[k]++;
      for (int i = 0; i < u1[k].size(); i++)
      {
        int w = u1[k][i][2];
        int des = u1[k][i][1];
        int src = u1[k][i][0];
        pq.push(make_pair(w,make_pair(src,des)));
      }
      
      // cout << "Help" << endl;
      while (!pq.empty())
      {
        auto it = pq.top();
        pq.pop();
        
        int src = it.second.first;
        int des = it.second.second;
        int w = it.first;
        
        if (MST_vertex.find(des) == MST_vertex.end())
        {
          MST_vertex[des]++;
          time[des-1] = w + time[src-1];
          maxi = max(maxi,time[des-1]);
          // cout << des << endl;
          for (int i = 0; i < u1[des].size(); i++)
          {
            int w = u1[des][i][2];
            int desi = u1[des][i][1];
            int srci = u1[des][i][0];
            
            // cout << "Here" << endl;
            if (MST_vertex.find(desi) == MST_vertex.end())
              pq.push(make_pair(w,make_pair(srci,desi)));
          }
          // cout << "If Loop" << endl;
        }
      }
      // cout << MST_vertex.size() << endl;
      return (MST_vertex.size() == n) ? maxi : -1;
    }
};
*/
class Solution {
 
  unordered_map<int,vector<vector<int>>> u1;
  void make_adjlist(vector<vector<int>> times)
  {
    for (int i = 0; i < times.size(); i++)
    {
      int src = times[i][0];
      u1[src].push_back(times[i]);
    }
  }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      make_adjlist(times);  
      vector<int> time(n+1,INT_MAX);
      
      queue<int> q;
      q.push(k);
      time[k] = 0;
      
      while (!q.empty())
      {
        int temp = q.front();
        q.pop();
        
        for (int i = 0 ; i < u1[temp].size(); i++)
        {
          int w = u1[temp][i][2];
          int des = u1[temp][i][1];
          if (time[des] > w + time[temp])
          {
            time[des] = w + time[temp];
            q.push(des);
          }
        }
      }
      
      int maxi = -1;
      for (int i = 1; i < time.size(); i++)
        maxi = max(time[i],maxi);
      
      return (maxi == INT_MAX) ? -1 : maxi;
    }
};