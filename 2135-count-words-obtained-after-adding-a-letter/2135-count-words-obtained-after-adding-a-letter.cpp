class Solution {
  /*We need to know whether after removing one alphabet from a string of targetwords we can get
  start word for searching we can use STL or hash maps or even sets can be used.
  Also sorting each one will help too.*/
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
      
      /*Sorting each string of startword and adding to hap maps*/
      
      unordered_map<string,int> mp;
      for (int i = 0; i < startWords.size(); i++)
      {
        sort(startWords[i].begin(),startWords[i].end());
        mp[startWords[i]]++;
      }
      
      int answer = 0;
      for (int i = 0; i < targetWords.size(); i++)
      {
        sort(targetWords[i].begin(),targetWords[i].end());
        bool flag = false;
        for (int j = 0; j < targetWords[i].size(); j++)
        {
          string temp;
          temp += targetWords[i].substr(0,j);
          temp += targetWords[i].substr(j+1);
          
          if (mp.find(temp) != mp.end())
            flag = true;
        }
        if (flag)
          answer++;
      }
      return answer;
    }
};