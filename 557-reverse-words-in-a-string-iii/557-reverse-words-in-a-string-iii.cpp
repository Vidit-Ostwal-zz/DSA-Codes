class Solution {
  void reverse(string& s, int start, int end)
  {
    end = end-1;
    while (start < end)
    {
      char temp = s[start];
      s[start] = s[end];
      s[end] = temp;
      start++;
      end--;
    }
  }
public:
    string reverseWords(string s) {
        int st = 0;
      int end = 0;
      
      while (end < s.length())
      {
        if (s[end] == ' ')
        {
          reverse(s,st,end);
          st = end+1;
        }
        end++;
      }
      reverse(s,st,end);
      return s;
    }
};