class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
      unordered_map<int,int> freq;
      
      for (int i = 0; i < tasks.size(); i++)
        freq[tasks[i] - 'A']++;
      
      priority_queue<int> pq;
      
      auto it =  freq.begin();
      
      while (it != freq.end())
      {
        pq.push(it->second);
        it++;
      }
      
      queue<pair<int,int>> cool_down;
      
      int time = 0;
      
      while (!pq.empty() || !cool_down.empty())
      {
        if (cool_down.size() && cool_down.front().first == time)
        {
          int CLProcSize = cool_down.front().second;
          cool_down.pop();
          pq.push(CLProcSize);
        }
        
        if (pq.size())
        {
          int pro_size = pq.top();
          pq.pop();
          pro_size--;
          
          if (pro_size)
            cool_down.push(make_pair(time + n + 1,pro_size));
        }
        
        time++;
      }
      return time;
    }
};