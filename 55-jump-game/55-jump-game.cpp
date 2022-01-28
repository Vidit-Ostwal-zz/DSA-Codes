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
   
  
  bool top_down_solution(vector<int>& nums)
  {
    vector<bool> reach(nums.size(),false);
    int i = 0;
    reach[i] = true;

    for (int k = 0; k < nums.size();k++)
    {
      if (reach[k])
      {
        int jump = nums[k]+k;
        while (i <= jump && i < nums.size())
        {
          reach[i] = true;
          i++;
        }
      }
    }
    return reach[reach.size()-1];
  }
public:
    bool canJump(vector<int>& nums) {
      return top_down_solution(nums);
      vector<int> dp(nums.size(),-1);
        return recursion(nums,0,dp);
    }
};