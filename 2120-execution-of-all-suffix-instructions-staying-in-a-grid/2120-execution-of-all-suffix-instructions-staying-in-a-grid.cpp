class Solution {
  int Helper(int i, string s, int n, int x, int y)
  {
    int count = 0;
    while (i < s.length())
    {
      if (s[i] == 'R')
        x++;
      else if (s[i] == 'L')
        x--;
      else if (s[i] == 'U')
        y--;
      else
        y++;
      
      if (x < 0 || y < 0 || x >= n || y >= n)
        return count;
      
      count++;
      i++;
    }
    return count;
  }
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
      
      vector<int> answer;
      
      for (int i = 0; i < s.length(); i++)
      {
        answer.push_back(Helper(i,s,n,startPos[1],startPos[0]));
      }
      return answer;
    }
};