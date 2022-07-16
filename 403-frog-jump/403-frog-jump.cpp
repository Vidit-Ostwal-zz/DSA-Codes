class Solution {
  unordered_map<int,set<int>> mapping;
public:
    bool canCross(vector<int>& stones) {
      
      mapping[0].insert(0);
        
      for (int i = 0; i < stones.size(); i++)
      {    
        set<int> temp = mapping[stones[i]];
        
        for (auto s : temp)
        {
          mapping[stones[i] + s - 1].insert(s-1);
          mapping[stones[i] + s].insert(s);
          mapping[stones[i] + s + 1].insert(s+1);
        }
      }
      return mapping[stones[stones.size()-1]].size() != 0;
    }
};