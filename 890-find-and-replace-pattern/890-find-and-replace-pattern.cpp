class Solution {
  bool isIsomorphic(string s, string t) {
      if (s.length() != t.length())
        return false;
      
      unordered_map<char,char> forward;
      unordered_map<char,char> backward;
      
      for (int i = 0; i < s.length(); i++)
      {
        if (forward.find(s[i]) != forward.end())
        {
          if (forward[s[i]] != t[i])
            return false;
        }
        else
          forward[s[i]] = t[i];
        
        if (backward.find(t[i]) != backward.end())
        {
          if (backward[t[i]] != s[i])
            return false;
        }
        else
          backward[t[i]] = s[i];
      }
      return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> answer;
      
      for (int i = 0 ;i < words.size(); i++)
        if (isIsomorphic(words[i],pattern))
          answer.push_back(words[i]);
      
      return answer;
    }
};