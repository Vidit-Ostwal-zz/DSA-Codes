class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
      unordered_map<int,set<int>> map;
      unordered_map<int,vector<int>> u1_map;
      
      for (int i = 0; i < logs.size(); i++)
            map[logs[i][0]].insert(logs[i][1]);
      
      
      auto it = map.begin();
      while (it != map.end())
      {
        u1_map[it -> second.size()].push_back(it->first);
        it++;
      }
      vector<int> temp;
      for (int i = 1; i <= k; i++)
        temp.push_back(u1_map[i].size());
      
      return temp;
    }
};