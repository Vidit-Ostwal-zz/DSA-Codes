class Solution {
//   vector<vector<int>> dp;
//   unordered
//   bool check (string s, int st, int ed,  unordered_map<string,int> dictmap)
//   {
//     if (st == ed)
//     {
//       string k = "";
//       k += s[st];
      
//       if (dictmap[k])
//       {
//         dp[st][ed] = 1;
//         return true;
//       }
//       dp[st][ed] = 0;
//       return false;
//     }
    
//     if (dp[st][ed] != -1)
//     {
//       return (dp[st][ed]) ? true :  false;
//     }
    
//     string temp = s.substr(st,ed-st+1);
    
//     if (dictmap[temp])
//     {
//       dp[st][ed] = 1;
//       return true;
//     }
    
//     for (int i = st; i < ed; i++)
//     {
//       if (check(s,st,i,dictmap) && check(s,i+1,ed,dictmap))
//       {
//         dp[st][ed] = 1;
//         return true;
//       }
//     }
//     dp[st][ed] = 0;
//     return false;
//   }
  
  unordered_map<string,bool> dp_map;
  unordered_map<string,int> DictMap;
  
  bool check (string s)
  {
    if (s.length() == 0)
    {
      return true;
    }
    if (dp_map.find(s) != dp_map.end())
    {
      return dp_map[s];
    }
    
    if (DictMap[s])
    {
      return dp_map[s] = true;
    }
    
    string prefix = "";
    
    for (int i = 0; i < s.length()-1; i++)
    {
      prefix += s[i];
      
      if (check(prefix) && check(s.substr(i+1)))
      {
        return dp_map[s] = true;
      }
    }
    return dp_map[s] = false;
  }
  
  
public:
    bool wordBreak(string s, vector<string>& wordDict) {
     
      
      for (int i = 0; i < wordDict.size(); i++)
      {
        DictMap[wordDict[i]]++;
      }
      
      return check(s);
    }
};