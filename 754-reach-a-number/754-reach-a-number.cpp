class Solution {
public:
    int reachNumber(int target) {
        int n = 1;
      
      target = (target < 0) ? -1*target : target;
      while ((n * (n+1))/2 <=  target)
        n++;
      
      n--;
      /*cout << n << endl;*/
      
      int option1 = n + (target - (n*(n+1))/2) * 2;
      
      n++;
      while ((((n)*(n+1)/2) - target) % 2)
      {
        n++;
      }
      int option2 = n;
      
      cout << n << endl;
      cout << option1 << endl;
      cout << option2 << endl;
      return min(option1,option2);
    }
};