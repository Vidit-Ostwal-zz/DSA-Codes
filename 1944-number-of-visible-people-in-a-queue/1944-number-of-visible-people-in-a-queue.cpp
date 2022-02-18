class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> answer;
      stack<int>st;
      
      for (int i = heights.size()-1; i >= 0; i--)
      {
        int temp = 0;
        
        if (st.empty())
        {
          
        }
        else
        {
          while (!st.empty() && heights[i]> st.top())
          {
            temp++;
            st.pop();
          }
          
          if (!st.empty())
            temp++;
        }
        
        answer.push_back(temp);
        st.push(heights[i]);
      }
      reverse(answer.begin(),answer.end());
      return answer;
    } 
};