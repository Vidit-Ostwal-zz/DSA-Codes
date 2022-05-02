class Solution {
public:
    int uniqueLetterString(string s) {
        
      /*Will store the contribution of this particular index*/
      vector<int> answer(s.length(),0);
      
      unordered_map<char,vector<int>> u1;
      int res = 1;
      u1[s[0]].push_back(1);
      answer[0] = 1;
      
      // cout << 1 << "  ";
      for (int i = 1; i < s.length(); i++)
      {
        int temp = answer[i-1] + i + 1;
        int helper = 0;
        int size = (u1.find(s[i]) == u1.end()) ? 0 : u1[s[i]].size();
        
        if (u1.find(s[i]) == u1.end())
          helper = 0;
        else if (u1[s[i]].size() == 1)
          helper = -2*u1[s[i]][0];
        else
          helper = -2*(u1[s[i]][size-1] - u1[s[i]][size-2]) + -1*(u1[s[i]][size-2]) ;
          
        temp += helper;
        u1[s[i]].push_back(i + 1);
        answer[i] = temp;
        res += temp;
        // cout << temp << "  ";
      }
      return res;
    }
};