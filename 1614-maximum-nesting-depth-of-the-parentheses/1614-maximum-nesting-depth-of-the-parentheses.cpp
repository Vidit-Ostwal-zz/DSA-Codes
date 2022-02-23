class Solution {
public:
    int maxDepth(string s) {
        stack <char> st;
      
      int answer = 0;
      int i = 0;
      while (i != s.length())
      {
        if (s[i] == '(')
          st.push(s[i]);
        else if (s[i] == ')')
          st.pop();
        
        if (st.size() > answer)
          answer = st.size();
        
        i++;
      }
      return answer;
    }
};