class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
      
      vector<int> answer(temperatures.size(),0);
      
      for (int i = temperatures.size()-1; i >= 0; i--)
      {
        
        while (!st.empty() && temperatures[st.top()] <= temperatures[i])
          st.pop(); 
        
        if (!st.empty())
          answer[i] = (st.top()-i);
        else
          answer[i] = 0;
        
        st.push(i);
      }
      return answer;
    }
};