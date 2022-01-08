class Solution {
public:
    int minAddToMakeValid(string s) {
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
};