class Solution {
public:
    char findTheDifference(string s, string t) {
      unordered_map<char,int> mp;
      
      for (int i =0; i < s.length(); i++)
      {
        mp[s[i]]++;
        mp[t[i]]--;
      }
      mp[t[t.length()-1]]--;
      
      for (auto i : mp)
      {
        if (i.second == -1)
          return i.first;
      }
      return '0';
    }
};