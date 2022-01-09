/* Recursive Solution to a power function*/


class Solution {
public:
    double myPow(double x, signed int N) {
      double answer=  1;
      int n = N;
      while (n)
      {
        if (n&1)
        {
          answer *= x;
        }
        n = n /2;
        x *= x;
      }
      return N < 0 ? 1/answer : answer;
    }
};