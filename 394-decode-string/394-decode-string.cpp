class Solution {
public:
  string stack_approach (string s)
  {
    stack<int> int_stack;
    stack<char> char_stack;
    
    for (int i = 0 ; i < s.length() ;i++)
    { 
      int count = 0;
      if (s[i] >= '0' && s[i] <= '9')
      {
        while (s[i] >= '0' && s[i] <= '9')
        {
          count  = count * 10 + s[i] - '0';
          i++;
        }
        i--;
        int_stack.push(count);
      }
     
     
     else if (s[i] == ']')
     {
       string temp  = "";
       int count = 0;
       string result = "";
       if (!int_stack.empty())
       {
         count = int_stack.top();
         int_stack.pop();
       }
       
       while (!char_stack.empty() && char_stack.top() != '[')
       {
         temp = char_stack.top() + temp;
         char_stack.pop();
       }
       
       if (!char_stack.empty() && char_stack.top() == '[')
         char_stack.pop();
       
       while (count > 0 )
       {
         result = temp + result;
         count--;
       }
       
       for (int j = 0; j < result.length(); j++)
         char_stack.push(result[j]);
     
     }
     
     else if (s[i] == '[')
     {
       if (s[i-1] >= '0' && s[i-1] <= '9')
         char_stack.push(s[i]);
       else
       {
         char_stack.push(s[i]);
         int_stack.push(1);
       }
     }
      
     else
       char_stack.push(s[i]);
    
    }
    string result = "";
    while (!char_stack.empty())
    {
      result = char_stack.top() + result;
      char_stack.pop();
    }
    return result;
  }
  
    string decodeString(string s) {
        return stack_approach(s);
    }
};