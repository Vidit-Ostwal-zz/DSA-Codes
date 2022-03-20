class Solution {
  int check (vector<int> tops, vector<int> bottoms)
  {
    set<int> st(tops.begin(),tops.end());
    vector<int> temp(st.begin(),st.end());
    
    int answer = INT_MAX;
    
    for (int i = 0; i < temp.size(); i++)
    {
      int count = 0;
       bool flag = true;
      for (int j = 0; j < tops.size(); j++)
      {
       
        if (tops[j] != temp[i] && bottoms[j] != temp[i])
        {
          flag = false;
          break;
        }
        
        if (tops[j] != temp[i] && bottoms[j] == temp[i])
          count++;
      }
      if (flag)
        answer = min(answer,count);
    }
    return answer;
  }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       int option1 = check(tops,bottoms);
      int option2 = check(bottoms,tops);
      
      int mini = min(option1, option2);
      
      return (mini == INT_MAX) ? -1 :mini;
    }
};