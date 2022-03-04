class Solution {
public:
    bool judgeSquareSum(int c) {
        
      int st = 0; 
      int ed = sqrt(c);
      
      while (st <= ed)
      {
        long long temp = (long long)st*st + (long long)ed *ed;
        
        if (temp == c)
          return true;
        
        else if (temp > c)
          ed = ed - 1;
        
        else
          st = st + 1;
      }
      return false;
    }
};