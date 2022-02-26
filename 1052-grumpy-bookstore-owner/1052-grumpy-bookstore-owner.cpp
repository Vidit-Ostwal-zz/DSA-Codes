class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
      int max_answer = 0;
        for (int i = 0; i < grumpy.size(); i++)
          if (grumpy[i] == 0)
            max_answer += customers[i];
      
      int st = 0;
      int ed = minutes-1;
      
      int temp = 0;
      int temp1 = 0;
      for (int i = 0; i < minutes && i < customers.size(); i++)
      {
        temp+= customers[i];
        if (grumpy[i] == 0)
          temp1 += customers[i];
      }
      
      int ansi = INT_MIN;
      while (ed < customers.size())
      {
        ansi = max(ansi,max_answer-temp1+temp);
        cout << ansi << "   " ;
        temp -= customers[st];
        if (grumpy[st] == 0) temp1 -= customers[st];
        ed++;
        
        if (ed < customers.size())
        {
          if (grumpy[ed] == 0) 
            temp1 += customers[ed]; 
          
          temp += customers[ed];
        }
        st++;
      }
      return ansi;
    }
};