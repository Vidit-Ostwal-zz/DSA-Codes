class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> u1;
      
      vector<int> temp (100001,-1);
      temp[0] = 0;
      temp[1] = -1;
      temp[2] = 1;
      for (int i =3; i < temp.size(); i++)
      {
        int op1 = temp[i-3] + 1;
        int op2 = temp[i-2] + 1;
        
        if (op1 == 0)
          op1 = INT_MAX;
        if (op2 == 0)
          op2 = INT_MAX;
        
        temp[i] = min(op1,op2);
      }
      
      for (int i = 0; i < tasks.size(); i++)
        u1[tasks[i]]++;
      
      // cout << u1.size() << endl;
      int answer = 0;
     
      auto it  = u1.begin();
    
      while (it != u1.end())
      {
        // cout << "Help" << endl;
        int re = temp[it->second];
        if (re == -1)
          return -1;
        answer += re;
        it++;
      }
      return answer;
    }
};