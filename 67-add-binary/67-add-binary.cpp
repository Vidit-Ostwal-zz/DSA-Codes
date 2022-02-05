class Solution {
  string getaddstring(string a, string  b)
  {
    int index = a.length()-1;
    string answer = "";
    int car_for = 0;
    
    while (index >= 0)
    {
      int curr_digit = a[index] - '0' + b[index] - '0' + car_for;
      answer  = to_string(curr_digit%2) + answer;
      car_for = curr_digit /2;
      index--;
    }
    if (car_for != 0)
      answer = to_string(car_for) + answer;
    
    return answer;
  }
  
public:
    string addBinary(string a, string b) {
        if (a.length() == b.length())
          return getaddstring(a,b);
      
      else
      {
        if (a.length() < b.length())
          while (a.length() <  b.length())
            a  = '0' + a;
        
        else
          while (b.length() < a.length())
            b = '0' + b ;
      }
      return getaddstring(a,b);
      
    }
};