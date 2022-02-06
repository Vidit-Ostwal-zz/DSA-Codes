class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char,int> mp;
      
      int start = 0;
      int end = 0;
      int answer = 0;
      
      while (end < s.length())
      {
        mp[s[end]]++;
        
        while (mp[s[end]] > 1)
        {
          mp[s[start]]--;
          if (mp[s[start]] == 0)
            mp.erase(s[start]);
          
          start++;  
        }
        answer = max(answer, end -start+1);
        end++;
      }
      return answer;
    }
};