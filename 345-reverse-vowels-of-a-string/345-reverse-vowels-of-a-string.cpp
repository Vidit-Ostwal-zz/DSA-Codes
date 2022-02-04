class Solution {
public:
    string reverseVowels(string s) {
        int start = 0;
      int end = s.length()-1;
      
      while (start < end)
      {
        char st = s[start];
        if (st == 'a' || st == 'e' || st == 'i' || st == 'o' || st == 'u' || st == 'A' || st == 'E' || st == 'I' || st == 'O' || st == 'U')
        {}
        else
          start++;
        
        char ed = s[end];
        if (ed == 'a' || ed == 'e' || ed == 'i' || ed == 'o' || ed == 'u' || ed == 'A' || ed == 'E' || ed == 'I' || ed == 'O' || ed == 'U')
        {}
        else
          end--;
        
        if ((st == 'a' || st == 'e' || st == 'i' || st == 'o' || st == 'u' || st == 'A' || st == 'E' || st == 'I' || st == 'O' || st == 'U') && (ed == 'a' || ed == 'e' || ed == 'i' || ed == 'o' || ed == 'u' || ed == 'A' || ed == 'E' || ed == 'I' || ed == 'O' || ed == 'U'))
        {
          char temp = ed;
          s[end] = s[start];
          s[start] = temp;
          start++;
          end--;
        }
      }
      return s;
    }
};