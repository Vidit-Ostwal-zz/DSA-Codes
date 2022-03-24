#include<string>


class Solution {
  
  string get_reverse(string temp)
  {
    int st = 0;
    int ed = temp.length()-1;
    
    while (st < ed)
    {
      char ch = temp[ed];
      temp[ed] = temp[st];
      temp[st] = ch;
      st++;
      ed--;
    }
    return temp;
  }
public:
    int reverse(int y) {
      bool flag = false;
      long x = y;
      if (x < 0)
      {
        flag = true;
        x = x*-1;
      }
      
      string temp = to_string(x);
      
      temp = get_reverse(temp);
      
      long long f = stol(temp);
      
      if (flag)
        f = (f * -1);
      
      if (f > INT_MAX || f < INT_MIN)
        return 0;
      
      return f;
    }
};