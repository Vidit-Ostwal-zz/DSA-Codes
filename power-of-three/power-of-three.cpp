class Solution {
public:
    bool isPowerOfThree(int n) {
      if (n <= 0)
      {
        return false;
      }
      int power = log10(n)/log10(3);
        if (n == pow(3,power))
            {
              return true;
            }
      return false;
    }
};