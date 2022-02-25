class Solution {
  int answer = 0;
  
  string check_first(string s, int x)
  {
    /*ab*/
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == 'b')
      {
        if (!st.empty() && st.top() == 'a')
        {
          answer += x;
          st.pop();
        }
        
        else
          st.push(s[i]);
        
      }
      else
        st.push(s[i]);
    }
    string temp = "";
    while (!st.empty())
    {
      temp += st.top();
      st.pop();
    }
    
    cout << answer << endl;
    reverse(temp.begin(),temp.end());
    return temp;
  }
  
  string check_second(string s, int x)
  {
    /*ab*/
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == 'a')
      {
        if (!st.empty() && st.top() == 'b')
        {
          answer += x;
          st.pop();
        }
        
        else
          st.push(s[i]);
        
      }
      else
        st.push(s[i]);
    }
    string temp = "";
    while (!st.empty())
    {
      temp += st.top();
      st.pop();
    }
    
    cout << answer << endl;
    reverse(temp.begin(),temp.end());
    return temp;
  }
  
public:
    int maximumGain(string s, int x, int y) {
      
      if (x > y)
        check_second(check_first(s,x),y);
      else
        check_first(check_second(s,y),x);
      
      return answer;
    }
};