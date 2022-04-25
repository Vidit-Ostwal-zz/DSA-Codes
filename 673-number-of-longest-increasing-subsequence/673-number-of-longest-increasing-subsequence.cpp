class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
      vector<int> dp_new(nums.size(),0);
      
      int answer = 1;
      dp[0] = 1;
      dp_new[0] = 1;
      
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
        
        if (curr_max == 0)
          dp_new[i] = 1;
        else
        {
          int count = 0;
          
          for (int j = 0; j < i; j++)
          {
            if (dp[j] == curr_max && nums[i] >  nums[j]) 
              count += dp_new[j];
          }
          
          dp_new[i] = count;
        }
        
      }  
      
      int answerq = 0;
      
      for (int i = 0; i < dp_new.size(); i++)
      {
        cout << dp[i] << "    " << dp_new[i] << endl;
        if (dp[i] == answer)
          answerq += dp_new[i];
      }
      return answerq;
    }
};