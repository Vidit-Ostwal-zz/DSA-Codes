class Solution {
  vector<int> dp;
  int sum = 0;
  int solve(vector<int> candid,int target)
  {
    if (target == 0)
      return 1;
    
    if (target < 0)
      return 0;
    
    if (dp[target] != -1)
      return dp[target];
    
    int sum = 0;
    for (int i = 0 ; i < candid.size(); i++)
      sum += solve(candid,target-candid[i]);
    
    return  dp[target] = sum;
  }
public:
    int combinationSum4(vector<int>& candidates, int target) {
      dp = vector<int>(target+1,-1);  
      solve(candidates,target);
      
      return dp[target];
    }
};