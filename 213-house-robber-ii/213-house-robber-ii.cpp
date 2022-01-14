class Solution {
public:
  int bottom_up_solution (vector<int> nums, int n)
    {
    if (n == 1)
      return nums[0];
    
    if (n == 0)
      return 0;
    vector<int> dp(n);
        for (int i = 0; i < n ; i++)
        {
            if (i  < 2)
            dp[i] = (i == 0) ? nums[i] : max(nums[i],dp[i-1]);
            
            else
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
  }
  
    int rob(vector<int>& nums) {
      if (nums.size() == 1)
      {
        return nums[0];
      }
      vector<int> nums1(nums.begin(),nums.end());
      nums1.erase(nums1.begin());
        return max(bottom_up_solution(nums,nums.size()-1),bottom_up_solution(nums1,nums1.size()));
    }
};