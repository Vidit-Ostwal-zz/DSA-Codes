class Solution {
  int all_possible(vector<int> days, vector<int> cost, int index,vector<int>&dp)
  {
    if (index >= days.size())
      return 0;
    
    if (dp[index] != -1)
      return dp[index];
    
    int option1 = cost[0] + all_possible(days, cost, index+1,dp);
    
    int temp = index;
    int next_higher = days[index] + 7 - 1;
    while (index <  days.size() && days[index] <= next_higher)
      index++;
    int option2 = cost[1] + all_possible(days,cost,index,dp);
    
    next_higher = days[temp] + 30 - 1;
    while (index < days.size() && days[index] <= next_higher)
      index++;
    int option3 = cost[2] + all_possible(days,cost,index,dp);
    
    return dp[temp] = min(option1,min(option2, option3));
  }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      vector<int> dp(days.size(),-1);
        return all_possible(days,costs,0,dp);
    }
};