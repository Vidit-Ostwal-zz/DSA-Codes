class Solution {
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
public:
    int numMatchingSubseq(string s, vector<string>& words) {
      int answer = 0;  
      unordered_map <string,int> mp;
  
      for (int i = 0; i < words.size(); i++)
      {
        if (mp.find(words[i]) == mp.end())
          mp[words[i]] = isSubsequence(words[i],s);
        
        answer += mp[words[i]];
      }
      
      return answer;
    }
};