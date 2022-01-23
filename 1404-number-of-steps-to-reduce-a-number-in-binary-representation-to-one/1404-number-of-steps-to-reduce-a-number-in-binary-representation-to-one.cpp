class Solution {
  string add1 (string s)
  {
    int index = s.length()-1;
    
    while ( index >= 0 && s[index] - '0' == 1)
    {
      s[index] = '0';
      index--;
    }
    if (index >= 0)
    {
      s[index] = '1';
      return s;
    }
    else
    {
      s = '1' +s;
    }
    return s;
  }
public:
    int numSteps(string s) {
      int count = 0;
        while(s.size() != 1)
        {
          if (s[s.length()-1] - '0' == 0)
          {
            s = s.substr(0,s.length()-1);
          }
          else
          {
            s = add1(s);
          }
          count++;
        }
      return count;
    }
};