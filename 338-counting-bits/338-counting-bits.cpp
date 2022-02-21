class Solution {
  int no_bits(int n)
  {
    int count = 0;
    while (n > 0)
    {
      if (n & 1)
        count++;
      
      n = n >> 1;
    }
    return count;
  }
  
  vector<int> get_answer(int n)
  {
    vector<int> answer;
    for (int i = 0; i < n+1; i++)
      answer.push_back(no_bits(i));
    
    return answer;
  }
public:
    vector<int> countBits(int n) {
      return get_answer(n);
    }
};