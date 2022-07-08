class Solution {
  vector<vector<vector<long long>>> dp;
  
  long long Recursive_Solution(vector<int>&houses,int index, vector<vector<int>>&cost,int n, int partitions, int prev_color)
  {
    if (index == houses.size() && partitions == 0)
      return 0;
    else if (index == houses.size() && partitions)
      return INT_MAX;
    else if (partitions < 0)
      return INT_MAX;
    
    // DP check
    if (dp[index][partitions][prev_color] != -1)
      return dp[index][partitions][prev_color];
    
    // Houses is already coloured
    if (houses[index])
    {
      if (prev_color == 0 || houses[index] == prev_color)
        return dp[index][partitions][prev_color] = Recursive_Solution(houses,index+1,cost,n,partitions,houses[index]);
      else
        return dp[index][partitions][prev_color] = Recursive_Solution(houses,index+1,cost,n, partitions-1,houses[index]);
    }
    
    // House is not coloured
    long long temp_cost = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
      if (prev_color == i || prev_color == 0)
        temp_cost = min(temp_cost,cost[index][i-1] + Recursive_Solution(houses,index+1,cost,n,partitions,i));
      else
        temp_cost = min(temp_cost,cost[index][i-1] + Recursive_Solution(houses,index+1,cost,n,partitions-1,i));
    }
    
    return dp[index][partitions][prev_color] = temp_cost;
  }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
      
      dp = vector<vector<vector<long long>>>(101,vector<vector<long long>>(101,vector<long long>(21,-1)));
      long long final_cost = Recursive_Solution(houses,0,cost,n,target-1,0);
      
      return (final_cost >= INT_MAX) ? -1 : final_cost;
    }
};