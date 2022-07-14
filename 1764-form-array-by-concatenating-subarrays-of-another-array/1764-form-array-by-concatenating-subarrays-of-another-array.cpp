class Solution {
  
  // int index = -1;
  vector<int> MakeKMPVector(vector<int>& A)
  {
    int N = A.size();
    vector<int> KMPVector;
    KMPVector = vector<int>(N,0);
    
    int i = 1;
    int j = 0;
    
    while (i < N)
    {
      if (A[i] == A[j])
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
    
    return KMPVector;
  }
  
  vector<int> compare (vector<int>& A, vector<int>& B)
  {
    // Inside A you have to find B
    
    vector<int> KMPVector = MakeKMPVector(B);
    vector<int> answer;
    int i = 0;
    int j = 0;
    
    while (i < A.size())
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
      
      if (j == B.size())
      {
        answer.push_back(i);
        j = KMPVector[j-1];
      }
    }
    
    return answer;
   
  }
public:
  
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        // MakeKMPVector(nums);
      
      int index = -1;
      
      for (int i = 0; i < groups.size(); i++)
      {
        vector<int> temp = compare(nums,groups[i]);
        int size = groups[i].size();
        bool flag = false;
        
        for (int i = 0; i < temp.size(); i++)
        {
          int st = temp[i] - size + 1;
          
          if (st > index)
          {
            index = temp[i];
            flag = true;
            break;
          }
        }
        
        if (!flag)
          return false;
        
        // cout << index << endl;
      }
      return true;
    }
};