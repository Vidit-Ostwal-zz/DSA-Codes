class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
      
      for (int i = 0; i < asteroids.size(); i++)
      {
        int curr = asteroids[i];
        
        if (st.empty())
          st.push(curr);
        
        else if (curr > 0)
          st.push(curr);
        
        
        else if (curr < 0 && st.top() < 0)
          st.push(curr);
        
        else
        {
          bool flag = false;
          
          while (!st.empty() && (curr*st.top()) < 0)
          {
            if (abs(st.top()) > abs(curr))
            {
              flag = false;
              break;
            }
            
            else if (abs(st.top()) == abs(curr))
            {
              flag = false;
              st.pop();
              break;
            }
          
            else
            {
              flag= true;
              st.pop();
            }
          }
          
          if (flag)
            st.push(curr);
        }
      }
      
      vector<int> remain;
      while (!st.empty())
      {
        remain.push_back(st.top());
        st.pop();
      }
      reverse(remain.begin(),remain.end());
      return   remain;
    }
};