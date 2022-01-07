class Solution {
public:
  /*
  Time Complexity and Space Complexity = O(N)
  */
  string optimized_solution(string s)
  {
    string  answer = "";
    /*Handling the edge case*/
    if (s.length() < 2)
    {
      return s;
    }
    
    stack < char> st ;
    for (int i = 0 ; i < s.length(); i++)
    {
      if (!st.empty() && st.top() == s[i])
      {
        st.pop();
      }
      else
      {
        st.push(s[i]);
      }
    }
    while(!st.empty())
    {
      answer = st.top() + answer;
      st.pop();
    }
    return answer;
  }
  
  
  
    string removeDuplicates(string s) {
        return optimized_solution(s);
    }
};