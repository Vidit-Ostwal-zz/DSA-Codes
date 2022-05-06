class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
      
      for (int i = 0 ; i < s.length(); i++)
      {
        
        if (st.empty())
          st.push(make_pair(s[i],1));
        else if (st.top().first == s[i] && st.top().second == k-1)
        {
            st.pop();
        }
        else if (st.top().first == s[i])
        {
          auto it = st.top();
          st.pop();
          st.push(make_pair(s[i],it.second+1));
        }
        else
          st.push(make_pair(s[i],1));
        
        // cout << i << "         " << st.size() << endl;
      }
      
      string s1 = "";
      
      while (!st.empty())
      {
        auto it = st.top();
        st.pop();
        
        string temp = "";
        
        for (int i = 0; i < it.second; i++)
          temp += it.first;
        
        s1  = temp + s1;
      }
      return s1;
      
    }
};