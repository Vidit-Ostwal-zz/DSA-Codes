class Solution {
  int isPossible(vector<int> nums, int mid)
  {
    int count = 0;
    int sum = 0;
    int st = 0;
    
    while (st < nums.size())
    {
      sum = nums[st];
      
      while (st+1 < nums.size() && sum + nums[st+1] <=  mid)
      {
        sum += nums[st+1];
        st++;
      }
      st++;
      count++;
    }
    cout << count << "  " << mid << endl;
    return count;
  }
public:
    int splitArray(vector<int>& nums, int m) {
      // minimum number of partition 1;
      // maximum number of partition nums.size();
      
      int ed = 0;
      int st = 0;
      for (int i = 0; i < nums.size(); i++)
      {
        ed += nums[i];
        st = max(st, nums[i]);
      }
      
      int answer = 0;
      while (st <= ed)
      {
        cout << st <<  "                  " << ed << endl;
        int mid = st + ((ed - st)/2);
        
        int temp = isPossible(nums,mid);
        if (temp <= m)
        {
          answer = mid;
          ed = mid-1;
        }
        else if (temp > m)
        {
          st = mid+1;
        }
      }
      return answer;
    }
};