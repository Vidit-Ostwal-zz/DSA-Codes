class Solution {
public:
    int numTeams(vector<int>& rating) {
        unordered_map<int,int> mp_forw;
      unordered_map<int,int>  mp_back;
       unordered_map<int,int> mp_forw1;
      unordered_map<int,int>  mp_back1;
      
      for (int i = 0; i < rating.size(); i++)
      {
        for (int j = 0; j < i; j++)
        {
          if (rating[j] < rating[i])
            mp_back[i]++;
          else
            mp_back1[i]++;
        }
      }
      
      for (int i = rating.size()-1; i >= 0 ; i--)
      {
        for (int j = rating.size()-1; j > i; j--)
        {
          if (rating[j] > rating[i])
            mp_forw[i]++;
          else 
            mp_forw1[i]++;
        }
      }
      
//       for (int i = 0; i < rating.size(); i++)
//       {
//         for (int j = 0; j < i; j++)
//           if (rating[j] > rating[i])
//             mp_back1[i]++;
//       }
      
//       for (int i = rating.size()-1; i >= 0 ; i--)
//       {
//         for (int j = rating.size()-1; j > i; j--)
//           if (rating[j] < rating[i])
//             mp_forw1[i]++;
//       }
      
      int answer = 0;
      for (int i = 0; i < rating.size(); i++)
        answer += ((mp_forw[i]*mp_back[i]) + mp_forw1[i]*mp_back1[i]);
      
      return answer;
    }
};