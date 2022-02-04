class Solution {
  int count(int n)
  {
    if (n == 0)
      return 1;
    
    if (n < 3)
      return n;
    
    int answer = 0;
    
    for (int i = 0; i < n; i++)
    {answer += count(i) * count(n-i-1);}
    
    return answer;
  }
public:
    int numTrees(int n) {
      if (n == 0 ) return 0;
        return count(n);
    }
};