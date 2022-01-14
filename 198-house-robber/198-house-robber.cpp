class Solution {
public:
  int bottom_up_solution (vector<int> nums, int n)
    {
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
        return bottom_up_solution(nums,nums.size());
    }
};