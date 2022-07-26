class Solution {
  static bool comp(string A, string B)
  {
    int findA = A.find(' ');
    int findB = B.find(' ');
    
    string tempA = A.substr(findA+1);
    string tempB = B.substr(findB+1);
    
    if (tempA.compare(tempB) != 0)
      return (tempA.compare(tempB) < 0);
    return (A.compare(B) < 0);
  }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
      
      vector<string> digit_log;
      vector<string> letter_log;
      
      for (int i = 0; i < logs.size(); i++)
      {
        char last_char = logs[i][logs[i].length()-1];
        if (last_char >= '0' && last_char <= '9')
          digit_log.push_back(logs[i]);
        else
          letter_log.push_back(logs[i]);
      }
      
      sort(letter_log.begin(),letter_log.end(),comp);
      
     
      int i = 0;
      
      for (int j = 0; j < letter_log.size(); j++)
        logs[i++] = letter_log[j];
      
      for (int j = 0; j < digit_log.size(); j++)
        logs[i++] = digit_log[j];
      
      return logs;
    }
};