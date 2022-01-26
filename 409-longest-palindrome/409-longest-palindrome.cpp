class Solution {
public:
    int longestPalindrome(string s) {
      sort(s.begin(),s.end());
      stack<char> st;

      int answer = 0;
      for (int i = 0; i < s.length();i++)
      {
        if (!st.empty() && st.top() == s[i])
        {
          st.pop();
          answer++;
          answer++;
        }
        else
        {
          st.push(s[i]);
        }
      }
      if (!st.empty())
        answer++;
      
      return answer;
    }
};