class Solution {
public:
    int singleNumber(vector<int>& nums) {
      
      vector<int> count_vector(32,0);
      
      for (auto x:nums)
      {
        x = abs(x);
        int i = 0;
        while (x > 0)
        {
          count_vector[i++] += x%2;
          x  = x /2;
        }
      }
      
      int answer = 0;
      unsigned long long int power = 1;
      int i = 0;
      for (auto x:count_vector)
      {
        answer += (count_vector[i]%3)*power;
        power  = power*2;
        i++;
      }
      
      int count = 0;
      for (auto x:nums)
      {
        if (answer == x)
        {
          count++;
        }
      }
      if (count == 0 || count == 3)
      {
        return -1 * answer;
      }
      return answer;
    }
};