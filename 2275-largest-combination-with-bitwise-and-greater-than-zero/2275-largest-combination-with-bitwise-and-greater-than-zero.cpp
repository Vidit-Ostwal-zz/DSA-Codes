class Solution {
  vector<unordered_map<int,int>> dp;
  int Size = 0;
  int try_all (vector<int> candi, int index, int size, int temp)
  {
    if (size && temp == 0)
      return -1;
    
    if (index == candi.size())
    {
      if (temp > 0)
      {
        Size = max(Size,size);
        return size;
      }
      return -1;
    }
    
    if (dp[index].find(temp) != dp[index].end())
    {
      return dp[index][temp];
    }
    
    int s = 0;
    if (size == 0)
      s = max(s,try_all (candi,index+1,size+1,candi[index]));
    else
      s = max(s,try_all (candi,index+1,size+1,temp&candi[index]));
    
    s = max(s,try_all (candi,index+1,size,temp));
    
    return dp[index][temp] = s;
  }
  
  int try_new (vector<int> A)
  {
    int size = 0;
    queue<pair<int,int>> pq;
    
    pq.push(make_pair(A[0],1));
    size = 1;
    
    int i = 1;
    while (i < A.size())
    {
      int size = pq.size();
      
      for (int j = 0; j < size; j++)
      {
        auto it = pq.front();
        pq.pop();
        
        int t1 = it.first;
        int t2 = it.second;
        
        pq.push(it);
        
        if (t1 & A[i] > 0)
        {
          size = max(size,t2+1);
          pq.push(make_pair(t1&A[i],t2+1));
        }
      }
      
      i++;
    }
    return size;    
  }
  
  // No Recursaive Approach no, Dynamic Programing Approach required in this question
  // Question clearly states the bit wise operator in it, therefore first job is to analyze the bits and then approach the question and come 
  // up with a bit wise solution of the same 
  // Therefore, the BitWise set, why dynamic Programming cannot be applied first space will be so big that it will overly overshhot the given space
  // Constraint, 
//    Now think about the Bit Wise And, we have to take AND between the different number, now once a position bit will change its value to zero it can never be changed, basically we need to know which position bit is occuring for the maximum amount of times and how many times, indrectly if we 
//    do a AND between the number which made that position bit maximum, that position bit will still remain, intact and therefoer the answer would be
//    maximum amount of set bit in all the number
  // Therefore we need to find the bit wise notation, of all the number, and count how many times a bit is set at a particular location and the maximum will be the answer.
    
public:
    int largestCombination(vector<int>& candidates) {
      vector<int> count(33,0);
      int maxi = 0;
      for (int i = 0; i < candidates.size(); i++)
      {
        int num =  candidates[i];
        int j = 0;
        
        while (num)
        {
          count[j] += (num%2) ? 1: 0;
          j++;
          num = num >> 1;
          maxi = max(maxi,count[j-1]);
        }
      }
      
      
      return maxi;
    }
};