class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
      
      for (int i = 0; i < s.length(); i++)
        map[s[i]]++;
      
      priority_queue<pair<int,char>> pq;
      
      auto it = map.begin();
      
      while (it != map.end())
      {
        pq.push(make_pair(it-> second , it->first));
        it++;
      }
      
      string temp = "";
      while(!pq.empty())
      {
        auto pt = pq.top();
        string temp1 = "";
        int count = pt.first;
        
        while (count)
        {
          temp1 += pt.second;
          count--;
        }
        temp += temp1;
        pq.pop();
      }
      return temp;
    }
};