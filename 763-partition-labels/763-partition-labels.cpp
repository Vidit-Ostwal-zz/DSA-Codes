class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_index(26,0);
      for (int i = 0; i < s.length(); i++)
        last_index[s[i]-'a'] = i;
      
      int j = 0;
      int anchor = 0;
      vector<int> answer;
      for (int i = 0; i < s.length(); i++)
      {
        j = max(j,last_index[s[i] - 'a']);
        if (i == j)
        {
          answer.push_back(i-anchor+1);
          anchor = i+1;
        }
      }
      return answer;
    }
};