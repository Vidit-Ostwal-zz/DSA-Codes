class Solution {
public:
    int numberOfSteps(int num) {
        if (num < 2)
          return num;
      
      return (num%2) ? 1+numberOfSteps(num-1) : 1+numberOfSteps(num/2);
    }
};