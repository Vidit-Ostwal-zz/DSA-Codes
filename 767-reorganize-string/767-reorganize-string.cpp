class Solution {
public:
    string reorganizeString(string s) {
        
      unordered_map<int,int> freq;
      
      for (auto &it: s)
      {
        freq[it - 'a']++;
      }
      
      priority_queue<pair<int,int>> pq;
      queue<pair<int,pair<int,int>>> cool_down;
      
      auto it = freq.begin();
      
      while (it != freq.end())
      {
        pq.push(make_pair(it->second,it->first));
        it++;
      }
      
      int index = 0;
      string answer = "";
      
      while (!pq.empty() || !cool_down.empty())
      {
        if (cool_down.size() && index == cool_down.front().first)
        {
          auto pair = cool_down.front().second;
          cool_down.pop();
          pq.push(pair);
        }
        
        if (!pq.empty())
        {
          auto pair = pq.top();
          pq.pop();
          answer += ('a' + pair.second);
          int freq = pair.first-1;
          
          if (freq)
            cool_down.push(make_pair(index+2,make_pair(freq,pair.second)));
        }
        else
          return "";
        
        
        index++;
      }
      return answer;
    }
};