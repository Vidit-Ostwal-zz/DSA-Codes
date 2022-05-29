class Solution {
public:
    bool digitCount(string num) {
        map<char,int> u1;
      string temp = "";
      for (int i = 0; i < num.length(); i++)
        u1[num[i]]++;
      
      for (int i = 0; i < num.length(); i++)
        temp += to_string(u1['0' + i]);
      
      cout << temp << endl;
      return num.compare(temp) == 0;
    }
};