class Solution {
  /*int no_bits(int n)
  {
    int count = 0;
    while (n > 0)
    {
      if (n & 1)
        count++;
      
      n = n >> 1;
    }
    return count;
  }*/
  
  vector<int> get_answer(int n)
  {
    vector<int> answer;
    answer.push_back(0);
    if (n == 0)
      return answer;
    
    answer.push_back(1);
    if (n == 1)
      return answer;
    
    for (int i = 2; i < n+1; i++)
    {
      int temp = 0;
      temp += (i & 1);
      int j = i >> 1;
      answer.push_back(temp + answer[j]);
    }
    
    return answer;
  }
public:
    vector<int> countBits(int n) {
      return get_answer(n);
    }
};