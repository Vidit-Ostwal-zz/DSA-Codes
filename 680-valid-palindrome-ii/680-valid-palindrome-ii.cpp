class Solution {
  bool istruePalindrome(string s, int st, int ed)
  {
    int st1 = st;
    int ed1 = ed;
    
    while (st1 <= ed1)
    {
      if (s[st1] != s[ed1])
        return false;
      
      st1++;
      ed1--;
    }
    return true;
  }
public:
    bool validPalindrome(string s) {
        int i = 0;
      int j = s.length()-1;
      
      while (i <= j)
      {
        if (s[i] != s[j])
          return istruePalindrome(s,i+1,j) || istruePalindrome(s,i,j-1);
        
        i++;
        j--;
      }
      return true;
    }
};