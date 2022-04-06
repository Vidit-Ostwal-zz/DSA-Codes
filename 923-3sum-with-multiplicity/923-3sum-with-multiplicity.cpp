class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
      sort(nums.begin(),nums.end());
      int count = 0;
      int mod = 1000000007;
      for (int i = 0; i < nums.size(); i++)
      {
        // cout << i << endl;
        int f = target - nums[i];
        
        int st = i+1; 
        int ed = nums.size()-1;
        
        while (st <= ed)
        {
          // cout << st << "   " << ed << endl;
          if (nums[st] + nums[ed] > f)
            ed--;
          else if (nums[st] + nums[ed] < f)
            st++;
          else
          {
            if (nums[st] == nums[ed])
            {
              count += ((ed - st + 1)*(ed - st)/2)%mod;
              count = count%mod;
              break;
            }
            else
            {
            int count_st = 1;
            while (st <= ed && nums[st] == nums[st+1])
            {
              count_st++;
              st++;
            }
            
            int count_ed = 1;
            while (st <= ed && nums[ed-1] == nums[ed])
            {
              count_ed++;
              ed--;
            }
            st++;
            ed--;
            // cout << count_st << "  hfjhfjh  " << count_ed << endl;
            count += ((count_st)%mod*(count_ed)%mod);
            }
          }
        }
         // cout << "Count:   " << count << endl;
      }
      return count;
    }
};