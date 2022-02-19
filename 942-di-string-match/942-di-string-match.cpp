class Solution {
public:
    vector<int> diStringMatch(string s) {
        int st = 0;
      int ed = s.length();
      
      vector<int> answer;
      int i = 0;
      while (st < ed)
      {
        if (s[i] == 'I')
        {
          answer.push_back(st);
          st++;
        }
        else if (s[i] == 'D')
        {
          answer.push_back(ed);
          ed--;
        }
        i++;
      }
      answer.push_back(st);
      return answer;
    }
};