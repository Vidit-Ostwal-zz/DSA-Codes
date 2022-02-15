class Solution {
  int LIS (vector<int> nums, int index, int prev_index, vector<vector<int>>& dp)
  {
    if (index >= nums.size())
      return 0;
    
    if (dp[index][prev_index] != -1)
      return dp[index][prev_index];
    
    if (nums[index] > nums[prev_index])
      return dp[index][prev_index] = max(1+LIS(nums,index+1,index,dp),LIS(nums,index+1,prev_index,dp));
    
    return dp[index][prev_index] = LIS(nums,index+1,prev_index,dp);
  }
  
  /*
  vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
      int answer = INT_MIN;  
      for (int i = 0; i < nums.size(); i++)
        answer = max(answer,LIS(nums,i+1,i,dp));
      
      return answer+1;
      */
public:
    int lengthOfLIS(vector<int>& nums) {
      vector<int> dp(nums.size(),-1);
      
      int answer = 1;
      dp[0] = 1;
      for (int i = 1; i < nums.size(); i++)
      {
        int curr_max = 0;
        
        for (int j = 0; j < i; j++)
        {
          if (nums[i] > nums[j]) 
            curr_max = max(curr_max,dp[j]);
        }
        
        dp[i] = curr_max + 1;
        answer = max(answer,dp[i]);
      }
      
      return answer;
    }
};