class Solution {
  unordered_map<string,int> map1;
  unordered_map<string,pair<bool,vector<string>>> dp;
  
  pair<bool,vector<string>> Helper(string s)
  {
    
    if (dp.find(s) != dp.end())
      return dp[s];
    
    if (s.length() == 1)
    {
      vector<string> okay;
      if (map1[s])
      {
        okay.push_back(s);
        return dp[s] = make_pair(true,okay);
      }
      else
        return dp[s] = make_pair(false,okay);
    }
    
    vector<string> temp_vector;
    bool flag = false;
    
    if (map1[s])
    {
      flag = true;
      string k = "";
      k += s;
      // k += " ";
      temp_vector.push_back(k);
    }
    
    for (int i = 1; i < s.length(); i++)
    {
      auto left = Helper(s.substr(0,i));
      auto right = Helper(s.substr(i));
      
      if (left.first && right.first)
      {
        flag = true;
        
        for (int k = 0; k < left.second.size(); k++)
        {
          for (int l = 0; l < right.second.size(); l++)
          {
            string S = "";
            S += left.second[k];
            S += " ";
            S += right.second[l];
            temp_vector.push_back(S);
          }
        }
      }
    }
    
    return dp[s] = make_pair(flag,temp_vector);
  }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
      
      for (int i = 0; i < wordDict.size(); i++)
        map1[wordDict[i]]++;
      
      auto it = Helper(s);
      
      if (it.first)
      {
        set<string> set1(it.second.begin(),it.second.end());
        vector<string> answer(set1.begin(),set1.end());
        return answer;
      }
      return {};
    }
};