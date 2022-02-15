class Solution {
  vector<string> answer;
  
  void get_all (int max, int open , int close, string temp)
  {
    if (temp.length() == max * 2)
      answer.push_back(temp);
    
    string temp1(temp.begin(),temp.end());
    if (open < max)
    {
      temp += '(';
      get_all (max, open+1,close, temp);
    }
    
    if (close < open)
    {
      temp1 += ')';
      get_all (max,open,close+1,temp1);
    }
    
  }
public:
    vector<string> generateParenthesis(int n) {
      get_all(n,0,0,"");
      return answer;
    }
};