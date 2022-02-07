class Solution {
public:
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
};