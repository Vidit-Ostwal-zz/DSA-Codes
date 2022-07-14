class Solution {
  vector<int> KMP (string s)
  {
    vector<int> KMPVector(s.length(),0);
    
    // i will move forward and j will represent the starting
    int i = 1;
    int j = 0;
    
    while ( i < s.length())
    {
      if (s[i] == s[j])
      {
        j++;
        KMPVector[i] = j;
        i++;
      }
      else
      {
        if (j)
          j = KMPVector[j-1];
        else
        {
          s[i] = j;
          i++;
        }
      }
    }
    return KMPVector;
  }
  
public:
    int repeatedStringMatch(string a, string b) {
        
      vector<int> KMPVector = KMP (b);
      
      int i = 0;
      int j = 0;
      
      set<int> initial;
      int count = 1;
      
      while (i < a.length())
      {
        // cout << i << "   " << j << endl;
        if (i == 0 && initial.count(j))
          break;
        else if (i == 0)
          initial.insert(j);
        
        if (a[i] == b[j])
        {
          i++;
          j++;
        }
        else
        {
          if (j == 0)
            i++;
          else
            j = KMPVector[j-1];
        }
        
        if (j == b.length())
          return count;
        
        if (i == a.length())
        {
          count++;
          i = 0;
        }
      }
      return -1;
    }
};