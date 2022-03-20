class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
      int count = 0;
      for (int i = 0; i < directions.length(); i++)
      {
        if (st.empty())
          st.push(directions[i]);
        
        else
        {
          if (directions[i] == 'L')
          {
            if (st.top() == 'L')
              st.push(directions[i]);
            
            else if (st.top() == 'S')
              count += 1;
            
            else
            {
              int temp = 0;
              while (!st.empty() && st.top() == 'R')
              {
                temp ++;
                st.pop();
              }
              st.push('S');
              count += temp + 1;
            }
          }
          
            else if (directions[i] == 'R')
          {
            st.push('R');
          }
          
          else 
          {
            if (st.top() == 'S' || st.top() == 'L')
              st.push('S');
            
            else if (st.top() == 'R')
            {
              while (!st.empty() && st.top() == 'R')
              {
                count+=1;
                st.pop();
              }
              
              st.push('S');
            }  
          }
        }
      }
      return  count;
    }
};