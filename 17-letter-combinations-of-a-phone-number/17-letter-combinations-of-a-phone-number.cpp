
class Solution {
public:
  vector<string> getsubsets (string digits, int index, string temp, vector<string>&final_vector)
  {
    if (digits.size() == 0)
      return final_vector;
    
    
    if (index == digits.length())
    {
      final_vector.push_back(temp);
      return final_vector;
    }
    
    char index_digit = digits[index];
    int digit = int(index_digit) - 48;
 
    if (digit == 7 || digit == 9)
    {
      for (int i = 0; i < 4;i++)
      {
        char temp_char = 97 + ((digit-2)*3 + i);
        if(digit == 9)
        {
          temp_char = temp_char+1;
        }
        string temp_pass = temp+temp_char;
        getsubsets(digits,index+1,temp_pass,final_vector);
      }
    }
    else
    {
      for (int i = 0; i < 3;i++)
      { 
      
        char temp_char = 97 + ((digit-2)*3 + i);
        if(digit == 8)
        {
          temp_char = temp_char+1;
        }
        cout << temp_char << endl;
        string temp_pass = temp+temp_char;
        getsubsets(digits,index+1,temp_pass,final_vector);
      }
    }
    return final_vector;
  }
  
  
  
    vector<string> letterCombinations(string digits) {
        vector<string> final_vector;
      return getsubsets(digits,0,"",final_vector);
    }
};