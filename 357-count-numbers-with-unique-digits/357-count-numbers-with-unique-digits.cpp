class Solution {
  int help( int n)
  {
    int temp  = 9;
    
    n--;
    
    int k = 9;
    while (n)
    {
      temp = temp * k;
      k--;
      n--;
    }
    return temp;
  }
public:
  /*Logical Pattern */
    int countNumbersWithUniqueDigits(int n) {
      vector<int> answer(n+1,0);
      answer[0] = 1;
      
      for (int i = 1; i < answer.size(); i++)
        answer[i] = answer[i-1] + help(i);
      
      return answer[n];
    }
};