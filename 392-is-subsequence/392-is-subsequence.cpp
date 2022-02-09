class Solution {
public:
    bool isSubsequence(string s, string t) {
        int st = 0; 
      int et = 0;
      
      while (st != s.length() && et != t.length())
      {
        if (s[st] == t[et])
        {
          st++;
          et++;
        }
        else
          et++;
      }
      
      if (st == s.length())
        return true;
      
      return false;
      
    }
};