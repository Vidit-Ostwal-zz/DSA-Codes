class Solution {
public:
    bool canChange(string start, string target) {
        
      stack<pair<char,int>> st1;
      stack<pair<char,int>> st2;
      // ??
        

      for (int i = 0; i < start.length(); i++)
      {
        if (start[i] == 'L' || start[i] == 'R')
          st1.push(make_pair(start[i],i));
        
        if (target[i] == 'L' || target[i] == 'R')
          st2.push(make_pair(target[i],i));
      }
      
      if (st1.size() != st2.size())
        return false;
      
      while (!st1.empty() && !st2.empty())
      {
        auto fi = st1.top();
        auto sec = st2.top();
        
        st1.pop();
        st2.pop();
        
        if (fi.first  != sec.first)
          return false;
        
        if (fi.first == 'R')
          if (fi.second > sec.second)
            return false;
        
        if (fi.first == 'L')
          if (fi.second < sec.second)
            return false;
      }
      return true;
    }
};