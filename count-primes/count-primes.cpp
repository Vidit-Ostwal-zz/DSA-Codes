class Solution {
public:
  
  /*Sieve of Erothoneses*/
    int countPrimes(int n) {
      vector<bool> bool_vector(n,true);
      int count = 0;
      
      for (int i = 2; i * i< n; i++)
      {
        if (bool_vector[i])
        {
          for (int j = i * i ; j < n; j += i)
          {
            bool_vector[j] = false;
          }
        }
      }
      
      for(int i = 2; i < n ; i++)
      {
        if (bool_vector[i])
        {
          count++;
        }
      }
      
      
      return count;
    }
};