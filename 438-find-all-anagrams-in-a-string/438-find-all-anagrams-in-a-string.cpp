class Solution {
  
  bool check(string s, int index, string p)
  {
    string sub = s.substr(index,p.length());
    sort(sub.begin(),sub.end());
      if (sub.compare(p) == 0)
        return true;
    
    return false;
  }
  
  /*vector<int> answer;
      if (s.length() < p.length())
        return answer;
      sort(p.begin(),p.end());
        for (int i = 0; i <= s.length()-p.length(); i++)
        {
          if (check(s,i,p))
            answer.push_back(i);
        }
      return answer;*/

  /*Using Hash Map*/
  public:
    vector<int> findAnagrams(string s, string p) {
      unordered_map<char,int> ms,mp;
      int pl = p.length();
      int sl = s.length();
      vector<int> answer;
      
      if (sl < pl)
        return answer;
      
      for (int i = 0; i < pl;i++)
      {
        ms[s[i]]++;
        mp[p[i]]++;
      }
      
      for (int i = pl; i < sl; i++)
      {
        if (ms == mp)
          answer.push_back(i - pl);
        
        ms[s[i]]++;
        ms[s[i-pl]]--;
        
        if (ms[s[i-pl]] == 0)
          ms.erase(s[i-pl]);
      }
      if (ms == mp)
          answer.push_back(sl - pl);
      
      return answer;
    }
};