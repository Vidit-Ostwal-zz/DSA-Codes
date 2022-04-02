class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> u1;
      unordered_map<string,int> u2;
      
      for (int i = 0; i < words1.size(); i++)
        u1[words1[i]]++;
        
      vector<string> temp;
      auto it = u1.begin();
      while (it != u1.end())
      {
        if (it  -> second == 1)
          temp.push_back(it->first);
        it++;
      }
      
      for (int i = 0; i < words2.size(); i++)
        u2[words2[i]]++;
      
      int count = 0;
     for (int i = 0; i < temp.size(); i++)
       if (u2[temp[i]] == 1)
         count++;
      return count;
    }
};