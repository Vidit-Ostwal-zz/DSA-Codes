class Solution {
  bool iswordbreak(string s,vector<string> wordDict,unordered_map<string,bool> &mp)
  {
    if (s.length() == 0)
      return true;
    
    if (mp.find(s) != mp.end())
      return mp[s];
      
    string temp  = "";
    for (int i = 0; i < s.length();i++)
    {
      temp += s[i];
      if (find(wordDict.begin(),wordDict.end(),temp) != wordDict.end() && iswordbreak(s.substr(i+1,s.length()-i-1),wordDict,mp))
        return mp[s] = true;
    }
    return mp[s] = false;
  }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      unordered_map<string,bool> mp;
        return iswordbreak(s,wordDict,mp);
    }
};