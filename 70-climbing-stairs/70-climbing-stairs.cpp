class Solution {
public:
    int climbStairs(int n) {
        if (n  <  3)
          return n;
      
      int temp1 = 1;
      int temp2 = 2;
      int answer;
      while (n >=3)
      {
        answer = temp1 + temp2;
        temp1 = temp2;
        temp2 = answer;
        n--;
      }
      return answer;
    }
};