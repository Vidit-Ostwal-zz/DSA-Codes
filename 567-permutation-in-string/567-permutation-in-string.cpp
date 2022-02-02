class Solution {
public:
    bool checkInclusion(string p, string s) {
        unordered_map<char,int> ms,mp;
      int pl = p.length();
      int sl = s.length();
      vector<int> answer;
      
      if (sl < pl)
        return false;
      
      for (int i = 0; i < pl;i++)
      {
        ms[s[i]]++;
        mp[p[i]]++;
      }
      
      for (int i = pl; i < sl; i++)
      {
        if (ms == mp)
          return true;
        
        ms[s[i]]++;
        ms[s[i-pl]]--;
        
        if (ms[s[i-pl]] == 0)
          ms.erase(s[i-pl]);
      }
      if (ms == mp)
         return true;
      
      return false;
    }
};