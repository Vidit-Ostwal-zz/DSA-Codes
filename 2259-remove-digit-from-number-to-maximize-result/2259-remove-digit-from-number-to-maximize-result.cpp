class Solution {
public:
    string removeDigit(string number, char digit) {
      int maxi = INT_MIN;
      vector<string> top;
      
      for (int i = 0; i < number.length(); i++)
        {
          if (number[i] == digit)
          {
            string s1 = number.substr(0,i);
            string s2 = number.substr(i+1);
            
            s1 += s2;
            
            top.push_back(s1);
          }
        }
      sort(top.begin(),top.end());
      return top[top.size()-1];
    }
};