class Solution {
  
  /*int result(vector<int> nums, int index, int taken, vector<vector<int>>& dp)
  {
    if (index == nums.size())
      return 0;
    
    if (dp[index][taken] != -1)
      return dp[index][taken];
    
    return dp[index][taken] = max(result(nums,index+1,taken,dp),nums[index]* taken + result(nums,index+1,taken+1,dp));
  }
  */
    
  int get_st(vector<int> nums, int st , int max)
  {
    int i = st;
    while (i >= 0 && -1*nums[i] < max)
    {
      max = max + nums[i];
      i--;
    }
    return i+1;
  }
public:
    int maxSatisfaction(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      
      /*vector<vector<int>> dp(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));
      return result(satisfaction,0,1,dp);*/
      
      int i = 0;
      while (i < nums.size() && nums[i] < 0)
        i++;
      
      if (i == nums.size()-1)
        return 0;
      
      int j = i;
      int count = 0;
      for (; j < nums.size(); j++)
        count += nums[j];
      
      int st = get_st(nums,i-1,count);
      int answer = 0;
      int index = 1;
      for (int i = st; i < nums.size(); i++)
      {
        answer += index*nums[i];
        index++;
        cout << answer << endl;
      }
      return answer;
    }
};