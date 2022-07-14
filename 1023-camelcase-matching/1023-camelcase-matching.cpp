class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer;
      
      for (int i=  0; i < queries.size(); i++)
      {
        string temp = queries[i];
        
        int j = 0;
        int k = 0;
        
        while ((j < temp.length()) && (k < pattern.length()))
        {
          if (temp[j] == pattern[k])
          {
            k++;
            j++;
          }
          else
          {
            if ((temp[j] - 'a' >= 0) && (temp[j] - 'a' < 26))
            {
              j++;
            }
            else
              break;
          }
        }
        
        while ((j < temp.length()) && (temp[j] - 'a' >= 0) && (temp[j] - 'a' < 26))
        {
          j++;
        }
        
        if (j == temp.length() && k == pattern.length())
          answer.push_back(true);
        else
          answer.push_back(false);
      }
      return answer;
    }
};