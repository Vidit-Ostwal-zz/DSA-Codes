class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // Only two option can be the answer
      // Either positive maximum or negative minimum
      
      int pos_max = INT_MIN;
      int sum = 0;
      for (int i = 0; i < nums.size(); i++)
      {
        sum += nums[i];
        
        if (sum < 0)
          sum = 0;
        
        pos_max = max(pos_max,sum);
      }
      // cout << pos_max << endl;
      int neg_min = INT_MAX;
      sum = 0;
      for (int i = 0; i < nums.size(); i++)
      {
        sum += nums[i];
        
        if (sum > 0)
          sum = 0;
        
        neg_min = min(neg_min,sum);
      }
      
      return max(abs(pos_max),abs(neg_min));
      
    }
};