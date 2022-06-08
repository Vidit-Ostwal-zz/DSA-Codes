class Solution {
  bool isPalindrome(string s)
  {
    string temp = "";
    temp += s;
    reverse(temp.begin(),temp.end());
    
    return temp.compare(s) == 0;
  }
public:
    int removePalindromeSub(string s) {
      
      if (isPalindrome(s))
        return 1;
        int count_a = 0;
      int count_b = 0;
      
      for (int i = 0; i < s.length(); i++)
      {
        if (s[i] == 'a')
          count_a++;
        else
          count_b++;
      }
      
      if (count_a && count_b)
        return 2;
      return 1;
    }
};