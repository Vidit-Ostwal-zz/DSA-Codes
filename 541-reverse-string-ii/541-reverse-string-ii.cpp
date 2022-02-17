class Solution {
  void reverse(string &s, int start, int end)
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
    string reverseStr(string s, int k) {
      int n = s.length();
      int i = 2*k -1;
      int j = 0;
      for (; i < s.length();)
      {
        reverse(s,j,j +k );
        j = i+1;
        i += 2*k;
      }
      reverse(s,j,min(j+k,n));
      return s;
    }
};