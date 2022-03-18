class Solution {
  vector<string> split(string t)
  {
    vector<string> temp;
    int i = 0;
    int st = 0;
    
    while (i < t.length())
    {
      if (t[i] == ' ')
      {
        temp.push_back(t.substr(st,i-st));
          st = i+1;
      }
      i++;
    }
    temp.push_back(t.substr(st,i-st));
    return temp;
  }
public:
    bool wordPattern(string s, string t) {
      vector<string> temp = split(t);
      
      if (temp.size() != s.length())
        return false;
      
      unordered_map<char,string> forward;
      unordered_map<string,char> backward;
      
      for (int i = 0; i < s.length(); i++)
      {
        if (forward.find(s[i]) != forward.end())
        {
          if (forward[s[i]].compare(temp[i]))
            return false;
        }
        else
          forward[s[i]] = temp[i];
        
        if (backward.find(temp[i]) != backward.end())
        {
          if (backward[temp[i]] != s[i])
            return false;
        }
        else
          backward[temp[i]] = s[i];
      }
      return true;
    }
};