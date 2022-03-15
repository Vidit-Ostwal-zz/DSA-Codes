class Solution {
  /*Strings are mutable in C++*/
public:
    string minRemoveToMakeValid(string s) {
      stack<char> st1;
      stack<int> st2;
      
      string answer;
      for (int i = 0; i < s.length(); i++)
      {
        if (s[i] >= 'a' && s[i] <= 'z')
        { }
        else
        {
          if (s[i] == '(')
          {
            st1.push(s[i]);
            st2.push(i);
            s[i] = '*';
          }
          else
          {
            if (!st1.empty() && st1.top() == '(')
            {
              st1.pop();
              s[st2.top()] = '(';
              st2.pop();
            }
            else
              s[i] = '*';
          }
        }
      }
      
      for (int i=  0; i < s.length(); i++)
      {
        if (s[i] != '*')
          answer += s[i];
      }
      return answer;
    }
};