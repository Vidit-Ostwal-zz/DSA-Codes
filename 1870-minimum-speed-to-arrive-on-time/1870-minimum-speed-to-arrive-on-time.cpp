class Solution {
  double get_time (vector<int> dist, int speed)
  {
    double answer = 0 ;
    for (int i = 0; i < dist.size(); i++)
    {
      if (dist[i] % speed && i != dist.size()-1)
        answer += dist[i]/speed + 1;
      else
        answer += dist[i]/double(speed);
    }
    return answer;
  }
  
  /*Classical Binary Search return index if found, returns -1 if not found*/
int Binary_Search(vector<int> nums, int st, int ed,double target)
 {
  int answer = -1;
  while (st <= ed)
  {
    double mid = st + (ed - st) / double(2);
    double temp = get_time(nums,mid);
    
   if (temp <= target)
   {
     answer = mid;
     ed = mid - 1;
   }
    
   else if (temp > target)
    st = mid + 1;
    
  }
  return answer;
}
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
      int maxi = INT_MIN;
      if (hour  <= double(dist.size()-1))
        return -1;
      
      for (int i = 0; i < dist.size(); i++)
        maxi = max(maxi,dist[i]);
      
        return Binary_Search(dist,1,10000000,hour);
    }
};