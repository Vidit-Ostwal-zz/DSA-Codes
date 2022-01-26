class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int temp1 = cost[0];
      int temp2 = cost[1];
      for (int i = 2; i < cost.size(); i++)
        {
          int min1 = min(temp1,temp2);
        temp1 = temp2;
        temp2 = min1 + cost[i];
        }
      return min(temp2,temp1);
    }
};