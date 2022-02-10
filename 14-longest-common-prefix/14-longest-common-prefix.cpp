class Solution {
  
public:
    string longestCommonPrefix(vector<string>& strs) {
      
      string temp = "";
      int index = 0;
      
      int mat = INT_MAX;
      for (int i = 0; i < strs.size(); i++)
      {
        int le = strs[i].length();
        mat = min(le,mat);
      }
        
      
      for (int i = 0; i < mat; i++)
      {
        for (int j = 1; j < strs.size(); j++)
        {
          if (strs[j][i] != strs[0][i])
            return temp;
        }
        temp += strs[0][i];
      }
      return temp;
        
    }
};