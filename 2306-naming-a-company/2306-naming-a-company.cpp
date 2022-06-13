class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
      
      unordered_map<char,unordered_set<string>> firstcharmap;
      long long count = 0;
     
      for (auto&x:ideas)
        firstcharmap[x[0]].insert(x.substr(1));
      
      for (int i = 0; i < 26; i++)
      {
        auto &setA = firstcharmap['a' + i];
        for (int j = i+1; j < 26; j++)
        {
          auto &setB = firstcharmap['a' + j];
          
          long long inter = 0;
          
          for (auto& a : setA){
            if (setB.find(a) != setB.end())
              inter++;
          }
          
          count += 2*(setA.size()-inter)*(setB.size()-inter);
        }
      }
      return count;
    }
};