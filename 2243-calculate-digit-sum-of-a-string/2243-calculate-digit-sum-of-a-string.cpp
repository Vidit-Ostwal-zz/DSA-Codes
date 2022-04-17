class Solution {
public:
    string digitSum(string s, int k) {
      cout << s << endl;  
      if (s.length() <= k)
          return s;
      
      string temp = "";
      
      int i = 0;
      while (i < s.length())
      {
        int sum = 0;
        int f = i;
        for (int j = 0; j < k && f + j  < s.length(); j++)
        {
          sum += s[f+j] - '0';
          i++;
        }
        temp += to_string(sum);
        
      }
      return digitSum(temp,k);
    }
};