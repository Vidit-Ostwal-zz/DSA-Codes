class Solution {
  string change_string (string s)
  {
    string temp ="";
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] >= 'a' && s[i] <= 'z')
        temp += s[i];
      
      else if (s[i] >= 'A' && s[i] <= 'Z')
        temp += s[i] - 'A' + 'a';
      
      else if (s[i] >= '0' && s[i] <= '9')
        temp += s[i];
    }
    return temp;
  }
public:
    bool isPalindrome(string s) {
      s = change_string(s);
      
      int st = 0;
      int ed = s.length()-1;
      
      while (st < ed)
      {
        if (s[st] != s[ed])
          return false;
        
        st++;
        ed--;
      }
      return true;
    }
};