class Solution {
  int KMPSearch (string a, string b)
  {
    // cout << a << "   " << b << endl;
    string temp = b + " " + a;
    
    vector<int> KMPVector(temp.length(),0);
    
    int i = 1;
    int j = 0;
    
    while (i < KMPVector.size())
    {
      if (temp[i] == temp[j])
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
          KMPVector[i] = 0;
          i++;
        }
      }
    }
    
    for (int i = 0; i < temp.length(); i++)
    {
      if (KMPVector[i] == b.length())
        return true;
    }
     // cout << "Here" << endl;
    return false;
  }
  
  int KMPSearch1 (string A, string B)
  {
    vector<int> KMPVector(B.length(),0);
    
    int i = 1;
    int j = 0;
    
    while (i < B.length())
    {
      if (B[i] == B[j])
      {
        j++;
        KMPVector[i] = j;
        i++;
      }
      else
      {
        if (j == 0)
        {
          KMPVector[i] = 0;
          i++;
        }
        else
          j = KMPVector[j-1];
      }
    }
    
    i = 0;
    j = 0;
    
    while (i < A.length())
    {
      if (A[i] == B[j])
      {
        i++;
        j++;
      }
      else 
      {
        if (j)
          j = KMPVector[j-1];
        else
          i++;
      }
      
      if (j == B.length())
        return true;
    }
    return false;
  }
public:
    int maxRepeating(string sequence, string word) {
      
      int max_answer = sequence.length()/word.length();
      int min_answer = 1;
      
      
      int answer = 0;
      while (min_answer <= max_answer)
      {
        int mid = min_answer + (max_answer - min_answer)/2;
        
        string temp = "";
        int k = mid;
        
        while (k)
        {
          temp += word;
          k--;
        }
        
        if (KMPSearch1(sequence,temp))
        {
          answer = mid;
          min_answer = mid + 1;
        }
        else
        {
          max_answer = mid - 1;
        }
      }
      return answer;
    }
};