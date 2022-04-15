class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        
      vector<int> first(security.size(),1);
      
      for (int i = 1; i < security.size(); i++)
      {
        if (security[i] <= security[i-1])
          first[i] = 1 + first[i-1];
      }
      
      vector<int> second(security.size(),1);
      
      for (int i = security.size()-2; i >= 0; i--)
      {
        if (security[i] <= security[i+1])
          second[i] = 1 + second[i+1];
      }
      
      
//       for (int i = 0; i < security.size(); i++)
//         cout << first[i] << "  ";
//       cout << endl;
//       for (int i = 0; i < security.size(); i++)
//         cout << second[i] <<  "  ";
      vector<int> answer;
      
      for (int i = 0; i < security.size(); i++)
      {
        if (first[i] >= time+1 && second[i] >= time+1)
          answer.push_back(i);
      }
      return answer;
    }
};