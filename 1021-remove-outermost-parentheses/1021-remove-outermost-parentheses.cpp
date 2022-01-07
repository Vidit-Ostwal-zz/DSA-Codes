class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
      int start = 0;
      int index = 0;
      string answer = "";
      while (index < s.length())
      {
        if (s[index] == '(')
        {
          st.push(s[index]);
        }
        else
        {
          st.pop();
        }
        
        if (st.empty())
        {
          if (start != index)
          {
            while (start + 1 < index)
            {
              answer += s[start+1];
              start++;
            }
            start = index+1;
          }
        }
        index++;
      }
      
      return answer;
    }
};