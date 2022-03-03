class Solution {
public:
    int minSteps(string s, string l) {
        unordered_map<char,int> mp;
      
      for (int i = 0; i < s.length(); i++)
      {
        mp[s[i]]++;
        mp[l[i]]--;
      }
      
      int count = 0;
      auto it = mp.begin();
      
      while (it != mp.end())
      {
        count += abs(it -> second);
        it++;
      }
    
      return count/2;
    }
};