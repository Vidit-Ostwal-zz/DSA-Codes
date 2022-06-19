class Solution {
public:
    int longestSubsequence(string s, int k) {
        int zero_count = 0;
      
      for (int i = 0; i < s.length(); i++)
      {
        if (s[i] == '0')
          zero_count++;
      }
      
      string temp = "";
      for (int i = s.length()-1; i >= 0 ; i--)
      {
        temp = s[i] + temp;
        
        if ( temp.length() <= 31 && stoll(temp,0,2) <= k)
        {
          if (s[i] == '1')
            zero_count++;
        }
        else
          break;
      }
      
      
      return zero_count;
    }
};