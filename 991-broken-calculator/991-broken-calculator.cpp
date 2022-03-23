class Solution {
public:
    int brokenCalc(int startValue, int target) {
      int count = 0;  
      while (startValue < target)
        {
          if (target&1)
            target++;
          else
            target = target/2;
          
          count++;
        }
      return count + abs(startValue-target);
    }
};