class Solution {
public:
    string getSmallestString(int n, int k) {
        string s = "";
      
      while (n)
      {
        int f = (n-1)*26;
        
        if (f >= k)
        {
          s += 'a';
          k -= 1;
        }
        else
        {
          int temp = k - f;
          char ch = 'a' + temp - 1;
          s+= ch;
          k -= temp;
        }
        n--;
      }
      return s;
    }
};