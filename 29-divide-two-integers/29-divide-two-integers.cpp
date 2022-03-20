class Solution {
public:
    int divide(int dividend, int divisor) {
      if (dividend/long(divisor) > long(INT_MAX))
        return INT_MAX;
      
      if (dividend/long(divisor) < long(INT_MIN))
        return INT_MIN;
      
        return dividend/divisor;
    }
};