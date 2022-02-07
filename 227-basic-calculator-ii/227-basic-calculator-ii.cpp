class Solution {
  
  string getString(char x)
  {
    string s = "";
    s += x;
    return s;
  }
  
  
  int prio(char c)
    {
        if (c == '^')
        return 3;
        
        if (c == '/' || c == '*')
        return 2;
        
        if (c == '+' || c == '-')
        return 1;
        
        return -1;
    }
  
  vector<string> infixToPostfix(string s)
    {
        stack<char> st;
        vector<string> answer;
       
        for (int i = 0; i < s.length();i++)
        {
            char c= s[i];
    
          if (c != ' ')
          {
            if (c >= '0' && c <= '9')
            {
              if (i > 0 && s[i-1] >= '0' && s[i-1] <= '9')
                answer[answer.size()-1] += getString(c);
              
              else
                answer.push_back(getString(c));
            }
            
            else
            {
                while (!st.empty() && prio(st.top()) >= prio(c))
                {
                    answer.push_back(getString(st.top()));
                    st.pop();
                }
                st.push(c);
            }
          }
        }
        
        while(!st.empty())
        {
             answer.push_back(getString(st.top()));
             st.pop();
        }
        return answer;
    }
  
 int evalRPN(vector<string>& tokens) {
      int answer = 0;
      stack<string> st;
        for (int i = 0; i < tokens.size(); i++)
        {
          string c = tokens[i];
          if (c == "+" || c == "-" || c == "*" || c == "/")
          {
            int num1 = stoi(st.top());
            st.pop();
            int num2 = stoi(st.top());
            st.pop();
            
            int result = 0;
            if (c == "+")
              result = num1+num2;
            else if (c == "-")
              result = num2-num1;
            else if (c == "*")
              result = num1*num2;
            else
              result = num2/num1;
            
            cout << result << endl;
            st.push(to_string(result));
          }
          else
            st.push(c);
        }
      return stoi(st.top());
    }
  
public:
    int calculate(string s) {
      vector<string> temp = infixToPostfix(s);
        return evalRPN(temp);
    }
};