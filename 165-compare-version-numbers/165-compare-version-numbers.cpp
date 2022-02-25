class Solution {
  vector<int> getrevision(string version1)
  {
    vector<int> answer;
    int start = 0;
    int temp = 0;
    
    while (start < version1.length())
    {
      if (version1[start] == '.')
      {
        answer.push_back(stoi(version1.substr(temp,start)));
        temp = start + 1;
      }
      start++;
    }
    answer.push_back(stoi(version1.substr(temp,start)));
    return answer;
  }
public:
    int compareVersion(string version1, string version2) {
        vector<int> p1 = getrevision(version1);
      vector<int> p2 = getrevision(version2);
      
      while (p1.size() < p2.size())
        p1.push_back(0);
      
      while (p2.size() < p1.size())
        p2.push_back(0);
      
      int i = 0;
      while (i < p1.size())
      {
        if (p1[i] == p2[i])
        {}
        
        else if (p1[i] > p2[i])
          return 1;
        
        else if (p1[i] < p2[i])
          return -1;
        
        i++;
      }
      return 0;
    }
};