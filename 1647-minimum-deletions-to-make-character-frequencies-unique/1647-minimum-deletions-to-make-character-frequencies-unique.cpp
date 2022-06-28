class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end());
      set<int> st;
      int sta = 0;
      int del = 0;
      for (int i = 1; i <= s.length(); i++)
      {
        while (i < s.length() && s[i] == s[i-1])
          i++;
        
        int freq = i-sta;
        cout << freq << endl;
        while (freq && st.count(freq))
        {
          freq--;
          del++;
        }
        
        st.insert(freq);
        sta = i;
        // i++;
      }
      return del;
    }
};