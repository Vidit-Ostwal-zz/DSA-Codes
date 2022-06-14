class Solution {
  set<vector<int>> set_of_answers; 
  void Recursive_Approach(string s, string t, int indexS, int indexT , vector<int> temp)
  {
    if (indexT == t.length())
    {
      if (temp.size() == t.length())
      {
        // show_vector(temp);
        set_of_answers.insert(temp);
      }
      return;
    }
    
    if (indexS == s.length())
      return;
    
    if (s[indexS] == t[indexT])
    {
      temp.push_back(indexS);
      Recursive_Approach(s,t,indexS+1,indexT+1,temp);
      temp.pop_back();
    }
    
    Recursive_Approach(s,t,indexS+1,indexT,temp);
    return;
  }
public:
    int numDistinct(string s, string t) {
      //   Recursive_Approach(s,t,0,0,{});
      // return set_of_answers.size();
      
      
      // DP will store the answer till now;
      
      vector<vector<double>> DP(s.length()+1,vector<double>(t.length()+1,0));
      
      
      // i-1 is representing the index of string s
      // j-1 is representing the index of string t;
      for (int i = 0; i < DP.size(); i++)
      {
        for (int j = 0; j < DP[0].size(); j++)
        {
          // desired string is empty
          if (j == 0)
            DP[i][j] = 1;
          
          // this cannot satisfy our conditions
          else if (j > i)
            DP[i][j] = 0;
          
          else if (s[i-1] == t[j-1])
            DP[i][j] = DP[i-1][j] + DP[i-1][j-1];
          
          else
            DP[i][j] = DP[i-1][j];
        }
      }
      return DP[s.length()][t.length()];
    }
};