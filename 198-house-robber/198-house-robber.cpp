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
  
  
  int recursive_solution(vector<int> nums, int index)
  {
    if (index >= nums.size())
      return 0;
    
    return max(nums[index]+recursive_solution(nums,index+2),recursive_solution(nums,index+1));
  }
  
  int memoization_solution(vector<int> nums, int index,vector<int>&dp)
  {
    if (index >= nums.size())
      return 0;
    
    if (dp[index] != -1)
      return dp[index];
    
    return dp[index] = max(nums[index]+memoization_solution(nums,index+2,dp),memoization_solution(nums,index+1,dp));
  }
    int rob(vector<int>& nums) {
      vector<int>dp(nums.size(),-1);
      return memoization_solution(nums,0,dp);
      return recursive_solution(nums,0);
        return bottom_up_solution(nums,nums.size());
    }
};