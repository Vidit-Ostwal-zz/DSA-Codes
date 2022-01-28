class Solution {
  bool recursion(vector<int>& nums, int index,vector<int>&dp)
  {
    if (index >= nums.size()-1)
        return true;

    if (dp[index] != -1)
      return dp[index];
    
    bool flag = false;
    int jump = nums[index];
  
    for (int i = 1 ; i <= jump; i++)
    {
      flag = (dp[index+i] == -1) ? recursion(nums,index+i,dp) : dp[index+i];
      
      if (flag)
        break;
    }
    return dp[index] = flag;
  }
    
public:
    bool canJump(vector<int>& nums) {
      vector<int> dp(nums.size(),-1);
        return recursion(nums,0,dp);
    }
};