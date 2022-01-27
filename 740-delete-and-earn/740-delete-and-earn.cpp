class Solution {
  int recursive_solution(vector<int> nums,int index,unordered_map<int,int> mp)
  {
    if (index >= nums.size())
      return 0;
    
    int curr_val = nums[index]*mp[nums[index]];
    if (index == nums.size()-1)
      return curr_val;
    
    /*
    3 different choices
    1> index not taken by choice
    2> index taken and index+1 cannot be taken bcuz of index
    3> index taken and index+1 can also be taken 
    */
    bool flag = false;
    if (nums[index+1] != nums[index] + 1) flag = true;
    
    return max(recursive_solution(nums,index+1,mp),curr_val + ((flag) ? recursive_solution(nums,index+1,mp) : recursive_solution(nums,index+2,mp)));
  }
  
  
  int memo_solution(vector<int> nums,int index,unordered_map<int,int> mp,vector<int>&dp)
  {
    if (index >= nums.size())
      return 0;
    
    if (dp[index] != -1)
      return dp[index];
    
    int curr_val = nums[index]*mp[nums[index]];
    if (index == nums.size()-1)
      return dp[index] = curr_val;
    
    
    /*
    3 different choices
    1> index not taken by choice
    2> index taken and index+1 cannot be taken bcuz of index
    3> index taken and index+1 can also be taken 
    */
    bool flag = false;
    if (nums[index+1] != nums[index] + 1) flag = true;
    
    return dp[index] = max(memo_solution(nums,index+1,mp,dp),curr_val + ((flag) ? memo_solution(nums,index+1,mp,dp) : memo_solution(nums,index+2,mp,dp)));
  }
  
  int top_down_solution(vector<int>nums,unordered_map<int,int> mp)
  {

    vector<int> dp(nums.size());
    dp[0] = nums[0]*mp[nums[0]];

    if (nums.size() == 1)
      return dp[0];
    dp[1] = (nums[1] == nums[0] + 1) ? max(dp[0],nums[1]*mp[nums[1]]) : dp[0] + nums[1]*mp[nums[1]];

    for (int i = 2; i < nums.size();i++)
    {
      bool flag = false;
      if (nums[i] != nums[i-1] + 1) flag = true;
      
      dp[i] = max(dp[i-1],nums[i]*mp[nums[i]] + ((flag) ? dp[i-1] : dp[i-2]));
    }
    return dp[nums.size()-1];
  }
public:
    int deleteAndEarn(vector<int>& nums) {
      
      vector<int> unique_vector;
      unordered_map<int,int> mp;
        for (int i = 0 ;i <  nums.size(); i++)
        {
          mp[nums[i]]++;
          if (mp[nums[i]] == 1)
          {
            unique_vector.push_back(nums[i]);
          }
            
        }
      sort(unique_vector.begin(),unique_vector.end());
      return top_down_solution(unique_vector,mp);
      vector<int> dp (nums.size(),-1);
      return memo_solution(unique_vector,0,mp,dp);
    }
};