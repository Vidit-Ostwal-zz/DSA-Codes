class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
          return false;
      
      if (x == 0)
        return true;
      
      vector<int> number;
      while (x > 0 )
      {
        number.push_back(x%10);
        x = x / 10;
      }
      
      int i = 0;
      int j = number.size()-1;
      
      while (i < j)
      {
        if (number[i] != number[j])
          return false;
        i++;
        j--;
      }
      return true;
    }
};