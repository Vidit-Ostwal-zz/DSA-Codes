class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int st = 0;
      int ed = 0;
      
      int maxi = INT_MIN;
      int zero_count = 0;
      int one_count = 0;
      while (ed < nums.size())
      {
        if (nums[ed] == 0)
          zero_count++;
        else
          one_count++;
        
        if (zero_count == 2)
        {
          while (nums[st] != 0)
          {
            st++;
          }
          zero_count--;
          st++;
        }
        maxi = max(maxi,ed - st);
        ed++;
      }
      
      if (one_count == nums.size())
        return nums.size()-1;
      
      return maxi;
    }
};