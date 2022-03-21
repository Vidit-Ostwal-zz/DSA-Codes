class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
      if (s.length() <= 10)
        return {};
      
        unordered_map<string,int> map;
      
      int ed = 9;
      int st = 0;
      
      while (ed < s.length())
      {
        string t = s.substr(st,10);
        map[t]++;
        st++;
        ed++;
      }
      
      vector<string> final_vector;
      
      auto it = map.begin();
      while (it != map.end())
      {
        if (it -> second > 1)
          final_vector.push_back(it -> first);
        
        it++;
      }
      return final_vector;
    }
};