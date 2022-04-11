class Solution {
  
public:
    int countOrders(int n) {
      
      if (n == 1)
        return 1;
      
      if (n == 2)
        return 6;
      
      vector<long long > answer(n+1,1);
      answer[1] = 1;
      answer[2] = 6;
      int MOD = 1000000007;
      for (int i = 3; i < answer.size(); i++)
        answer[i] = ((i)*(2*i-1)*(answer[i-1]%MOD)%MOD);
      
      return answer[n];
    }
};