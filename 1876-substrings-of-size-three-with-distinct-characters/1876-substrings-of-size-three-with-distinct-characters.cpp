class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int> mp;
      
      for (int i = 0; i < 3;i++)
        mp[s[i]]++;
      
      int start = 0;
      int end = 3;
      
      int count = 0;
      for (int i = end; i < s.length();i++)
      {
        if (mp.size() == 3)
        {
          cout << i << endl;
           count++;
        }
        
        mp[s[i]]++;
        mp[s[start]]--;
        
        if (mp[s[start]] == 0)
          mp.erase(s[start]);
        
        start++;
      }
      if (mp.size() == 3)
        count++;
      
      return count;
    }
};