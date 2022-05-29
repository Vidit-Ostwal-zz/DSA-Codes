class Solution {
public:
    int maxProduct(vector<string>& words) {
        
      vector<vector<int>> vec1(words.size(),vector<int>(26,0));
      int maxi = 0;
      
      for (int i = 0; i < words.size(); i++)
        for (int j = 0; j < words[i].length(); j++)
          vec1[i][words[i][j] - 'a']++;
      
      for (int i = 0; i < words.size(); i++)
        for(int j = i+1; j < words.size(); j++)
        {
          bool f = true;
          for (int k = 0; k < 26; k++)
            if (vec1[i][k] && vec1[j][k])
            {
              f = false;
              break;
            }
         
          if (f)
            maxi = max(maxi,(int)words[i].length()*(int)words[j].length());
        }
      
      return maxi;
    }
};