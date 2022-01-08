class Solution {
public:
  int stack_apporach (string s)
  {
    stack <int> st;
        for (int i = 0; i < s.length(); i++)
        {
          char charac = s[i];
          if (charac == '(')
          {
            st.push(charac);
          }
          else if (!st.empty() && charac == ')' && st.top() == '(')
          {
            st.pop();
          }
          else
          {
            st.push(charac);
          }
        }
      return st.size();
  }
  
  int without_stack (string s)
  {
    int count = 0;
    int balance = 0;
    for (int i = 0; i < s.length(); i++)
    {
      balance += s[i] == '(' ? 1 : -1;
      if (balance  < 0)
      {
        count++;
        balance++;
      }
    }
    
    return count+balance;
  }
  
  
  
    int minAddToMakeValid(string s) {
      return without_stack(s);
    }
};