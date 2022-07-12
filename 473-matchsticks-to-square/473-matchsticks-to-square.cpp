class Solution {
  
  static bool comparator(int a, int b)
  {
    return a >= b;
  }
  
  long long max_length = 0;
  bool isPossible(vector<int>&A, int index, vector<long long> temp)
  {
    if (index == A.size())
    {
      if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3])
        return true;
      return false;
    }
    
    for (int i = 0; i < 4; i++)
    {
      if ((temp[i] + A[index]) <= max_length)
      {
         int j = i-1;
        
         while (j >= 0 && temp[j] != temp[i])
          j--;
        
        temp[i] += A[index];
        
       
        
       
        if (j == -1 && isPossible(A,index+1,temp))
          return true;
        
        temp[i] -= A[index];
      }
    }
    return false;
  }
public:
    bool makesquare(vector<int>& matchsticks) {
        
      long long total_sum = 0;
      
      for (int i = 0; i < matchsticks.size(); i++)
        total_sum += matchsticks[i];
      
      if (total_sum % 4)
        return false;
      
      max_length = total_sum/4;
      sort(matchsticks.begin(),matchsticks.end(),greater<int>());
      vector<long long> temp(4,0);
      return isPossible(matchsticks,0,temp);
    }
};