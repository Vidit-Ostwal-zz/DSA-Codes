class Solution {
  long long int getsum(long long int n)
  {
    return (n * (n+1))/2;
  }
public:
    int arrangeCoins(int n) {
        int st = 1;
      int ed = n;
      
      int answer = 0;
      while (st <= ed)
      {
        int mid = st + (ed -st) / 2;
        
        long long int temp = getsum(mid);
        
        if (temp == n)
          return mid;
        
        else if (temp > n)
          ed = mid - 1;
        
        else if (temp < n)
        {
          answer = mid;
          st = mid +1;
        }
      }
      return answer;
    }
};