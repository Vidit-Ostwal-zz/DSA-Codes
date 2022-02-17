class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX;
      int mini_index = 0;
      int maxi = INT_MIN;
      int maxi_index = 0;
      
      for (int i = 0; i < nums.size(); i++)
      {
        if (mini > nums[i])
        {
          mini = nums[i];
          mini_index = i;
        }
        
        if (maxi < nums[i])
        {
          maxi = nums[i];
          maxi_index = i;
        }
      }
      int temp1 = max(mini_index+1,maxi_index+1);
      int temp2 = max(nums.size()-mini_index,nums.size()-maxi_index);
      int temp3 = min(mini_index+1+nums.size()-maxi_index,maxi_index+1+nums.size()-mini_index);
      
      return min(min(temp1,temp2),temp3);
    }
};