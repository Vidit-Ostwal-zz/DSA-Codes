#include<string>
class Solution {
public:
    string minimizeResult(string expression) {
        int plus_i = -1;
      
      for (int i = 0; i < expression.length(); i++)
        if (expression[i] == '+')
          plus_i = i;
      
      string prev ="";
      string next = "";
      
      for (int i = 0; i < plus_i; i++)
        prev += expression[i];
      
      for (int i = plus_i+1; i < expression.length(); i++)
        next += expression[i];
      
    
       string num1 = "";
      string s_answer = "";
      int answer = INT_MAX;
      for (int j = 0; j < plus_i; j++)
      {
         
        string num2 = "";
        string num4 = "";
        string num3 = "";
        num2 = prev.substr(j);
        int numint1 = (num1.length()) ? stoi(num1) : 1;
        int numint2 = stoi(num2);
        for (int k = plus_i+1; k < expression.length(); k++)
        {
          num3 +=expression[k];
          num4 = (k+1 < expression.length()) ? expression.substr(k+1) : "1";
           // cout << num1 << "  " << num2 << "  " << num3 <<  "  " << num4 << endl;
          int numint3 = stoi(num3);
          int numint4 = stoi(num4);
          
          // answer = min(answer,numint1*(numint2 + numint3)*numint4);
          if (answer > numint1*(numint2 + numint3)*numint4)
          {
            answer = numint1*(numint2 + numint3)*numint4;
            s_answer = "";
            
            if (num1.length())
              s_answer += to_string(numint1);
            
            s_answer += "(";
            s_answer += to_string(numint2);
            s_answer += "+";
            s_answer += to_string(numint3);
            s_answer += ")";
            
            if (k+1 < expression.length())
              s_answer += to_string(numint4);
          }
          
        }
        num1 += expression[j];
      }
      return s_answer;
    }
};