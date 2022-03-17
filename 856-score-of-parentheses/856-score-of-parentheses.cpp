class Solution {
  int get_score(string s, int st, int ed)
  {
    cout << st << "    " << ed << endl;
    string temp = s.substr(st,2);
    
    if (temp.compare("()") == 0)
      return 1;
    
    int sum = 0;
    int i = st+1;
    int answer = 0;
    
    while (i < ed)
    {
      if (s[i] == '(')
        sum++;
      else
        sum--;
      
      if (sum == 0)
      {
        answer += get_score(s,st+1,i);
        st = i;
      }
      i++;
    }
    return 2*answer;
  }
public:
    int scoreOfParentheses(string s) {
      
      int i = 0;
      int answer = 0;
      int sum = 0;
      int st = 0;
      
      while (i < s.length())
      {
        if (s[i] == '(')
          sum++;
        else
          sum--;
        
        if (sum == 0)
        {
          answer += get_score(s,st,i);
          st = i+1;
        }
        i++;
      }
      return answer;
    }
};