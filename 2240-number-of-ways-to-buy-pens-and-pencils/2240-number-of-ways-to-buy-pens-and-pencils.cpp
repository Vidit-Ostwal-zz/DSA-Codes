class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
      long long at_max1 = total/cost1;
      long long  at_max2 = total/cost2;
      
      long long ans = 0;
      for (long long i = 0; i <= at_max1; i++)
        ans += ((total - i*cost1)/cost2) + 1;
      
      return ans;
    }
};