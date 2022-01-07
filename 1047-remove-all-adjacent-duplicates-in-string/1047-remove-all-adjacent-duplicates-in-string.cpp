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
  
  /*Without Stack directly appending in string*/
  string optimized_solution1(string s)
  {
    string  answer = "";
    /*Handling the edge case*/
    if (s.length() < 2)
    {
      return s;
    }
    for (int i = 0 ; i < s.length(); i++)
    {
      if (answer.length() != 0 && answer[answer.length()-1] == s[i])
      {
        answer.pop_back();
      }
      else
      {
        answer.push_back(s[i]);
      }
    }
    return answer;
  }
  
    string removeDuplicates(string s) {
        return optimized_solution1(s);
    }
};