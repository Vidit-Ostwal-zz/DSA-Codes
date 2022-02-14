class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> mp_left;
      unordered_map<char,int> mp_right;
      int count = 0;
      
      for (int i = 0; i < s.length(); i++)
        mp_right[s[i]]++;
      
      for (int i = 0; i < s.length();i++)
      {
        mp_right[s[i]]--;
        if(mp_right[s[i]] == 0)
          mp_right.erase(s[i]);
        
        mp_left[s[i]]++;
        
        if (mp_left.size() == mp_right.size())
          count++;
      }
      return count;
    }
};