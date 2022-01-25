class Solution {
public:
    int tribonacci(int n) {
        if (n == 0)
          return 0;
      if (n == 1)
        return 1;
      if (n == 2)
        return 1;
      
      int answer = 1;
      int prev1 = 1;
      int prev2 =0;
      for (int i = 3; i <= n; i++)
      {
        int temp = answer + prev1 + prev2;
        prev2 = prev1;
        prev1 = answer;
        answer = temp;
      }
      return answer;
    }
};