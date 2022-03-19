class Solution {
  int gcd (int A, int B)
  {
    if (B == 0)
      return A;
    return gcd(B,A % B);
  }
  
public:
  
  /*With Mathematical Approach We can say that if GCD of two backets divides target then its true otherwise false*/
  /*For the similar we can say GCD of two numbers wont change if we subtract smaller number from Bigger Number*/
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
      
      if (targetCapacity > jug1Capacity + jug2Capacity)
        return false;
      
        int gcd_num = gcd (jug1Capacity, jug2Capacity);
      return (targetCapacity % gcd_num) ? false : true;
    }
};