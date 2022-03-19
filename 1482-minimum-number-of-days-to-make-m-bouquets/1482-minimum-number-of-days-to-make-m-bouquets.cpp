class Solution {
  bool isPossible (vector<int> bloomday, int day, int m, int k)
  {
    vector<bool> bloomed;
    for (int i = 0; i < bloomday.size(); i++)
    {
      if (bloomday[i] <= day)
        bloomed.push_back(true);
      else
        bloomed.push_back(false);
    }
    
    int st = 0;
    while (!bloomed[st])
      st++;
    
    int i = st;
    vector<int> temp;
    while (st < bloomed.size())
    {
      while (st < bloomed.size() && bloomed[st])
        st++;
      temp.push_back(st-i);
      
      while (st < bloomed.size() && !bloomed[st])
        st++;
      
      i = st;
    }
    
    int count = 0;
    for (int i = 0; i < temp.size(); i++)
      count += temp[i]/k;
    
    return count >= m;
  }
  
  /*Classical Binary Search return index if found, returns -1 if not found*/
int Binary_Search(vector<int> bloomday, int st, int ed, int m, int k)
 {
  int answer = -1;
  while (st <= ed)
  {
   int mid = st + (ed - st) / 2;
  
    if (isPossible(bloomday,mid,m,k))
    {
     answer = mid;
     ed = mid - 1;
   }
    
    else{
      st = mid + 1;
    }
  }
  return answer;
}
public:
    int minDays(vector<int>& bloomday, int m, int k) {
      int maxi = INT_MIN;
      
      if (k == 1 && m == 1)
      {
        sort(bloomday.begin(),bloomday.end());
        return bloomday[m-1];
      }
        for (int i = 0; i < bloomday.size(); i++)
          maxi = max(bloomday[i],maxi);
      
      return Binary_Search(bloomday,0,maxi, m,k);
    }
};