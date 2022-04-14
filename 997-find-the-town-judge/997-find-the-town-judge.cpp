class Solution {
  unordered_map<int,vector<int>> u1;
  unordered_map<int,int> mp;
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        for (int i = 0; i < trust.size(); i++)
        {
          u1[trust[i][0]].push_back(trust[i][1]);
          mp[trust[i][1]]++;
        }
      
      for (int i = 1; i <= n; i++)
        if (u1.find(i) == u1.end() && mp[i] == n-1)
          return i;
      
      return -1;
    }
};