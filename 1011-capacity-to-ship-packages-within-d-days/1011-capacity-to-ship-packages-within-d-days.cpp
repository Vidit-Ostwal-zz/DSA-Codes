class Solution {
  bool cando (vector<int> weights, int days,int max_weight)
  {
    int count = 0;
    for (int i = 0; i < weights.size(); i++)
    {
      int curr = 0;
      
      curr += weights[i];
      if (curr > max_weight)
        return false;
      
      while (i + 1 < weights.size() && curr + weights[i+1] <= max_weight)
      {
        curr += weights[i+1];
        i++;
      }
      count++;
    }
    return (count <= days);
  }
  
  /*Classical Binary Search return index if found, returns -1 if not found*/
int Binary_Search(vector<int> nums, int st, int ed,int target)
 {
  int answer = -1;
  while (st <= ed)
  {
   int mid = st + (ed - st) / 2;
   bool flag = cando(nums,target,mid);
   if (flag)
   {
     answer = mid;
     ed = mid -1;
   }
    else
      st = mid + 1;
    
  }
  return answer;
}
public:
    int shipWithinDays(vector<int>& weights, int days) {
      int max = 0;
      for (int i = 0; i < weights.size(); i++)
        max += weights[i];
      return Binary_Search(weights,1,max,days);
    }
};