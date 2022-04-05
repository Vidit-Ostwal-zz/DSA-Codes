#include <string>
class Solution {
  
  unordered_map<int,string> u1_S;
  unordered_map<int,string> u1_M;
  vector<vector<int>> dp;
  // int get_sum (vector<vector<int>>& students, vector<vector<int>>& mentors, vector<int> temp)
  // {
  //   int sum  =0;
  //   for (int i=  0; i < temp.size(); i++)
  //   {
  //     for (int j = 0; j < mentors[0].size(); j++)
  //       if (mentors[i][j] == students[temp[i]][j])
  //         sum++;
  //   }
  //   return sum;
  // }
  
  int best_possible (vector<vector<int>>& students, vector<vector<int>>& mentors, vector<bool> flag, int index, vector<int> temp)
  {
    if (index == flag.size())
      return 0;
    
    int maxi =  INT_MIN;
    for (int i = 0; i < flag.size(); i++)
    {
      if (flag[i])
      {
        flag[i] = false;
        temp.push_back(i);
        
        int sum = dp[i][index];
        maxi = max (maxi,sum + best_possible(students, mentors,flag, index+1,temp));
        flag[i] = true;
        temp.pop_back();
      }
    }
    return maxi;
  }
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
      dp = vector<vector<int>> (students.size(),vector<int>(mentors.size(),0));
      /*for (int i = 0; i < students.size(); i++)
      {
        string temp = "";
        for (int j = 0; j < students[0].size(); j++)
          temp += (char)(students[i][j] + '0');
        
        u1_S[i] = temp;
      }
      
      for (int i = 0; i < mentors.size(); i++)
      {
        string temp = "";
        for (int j = 0; j < mentors[0].size(); j++)
          temp += (char)(mentors[i][j] + '0');
        
        // cout << temp << endl;
        u1_M[i] = temp;
      }*/
      for (int i = 0; i < mentors.size(); i++)
      {
        vector<int> mentor_temp(mentors[i].begin(),mentors[i].end());
        for (int j = 0 ; j < mentor_temp.size() ; j++)
          for (int k = 0; k < students.size(); k++)
            if (mentor_temp[j] == students[k][j])
              dp[k][i]++;
      }
      
      
      vector<bool> flag(students.size(),true);
        return best_possible (students, mentors, flag, 0,{});
    }
};