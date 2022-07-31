class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
      
      int c = 1;
      int count = 0;
      
      while (n >= 0)
      {
        n -= c;
        c++;
        
        if (n >= 0)
          count++;
      }
      return count;
    }
};