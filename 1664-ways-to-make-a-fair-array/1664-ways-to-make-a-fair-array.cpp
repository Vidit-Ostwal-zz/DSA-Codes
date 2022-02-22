class Solution {
public:
  /*
  te/to = total even / total odd
  ten/ton = total even till now/ total odd till now
  ate /ato = at this even / at this odd
  */
    int waysToMakeFair(vector<int>& nums) {
        int te = 0;
      int to = 0;
      
      for (int i = 0; i < nums.size(); i++)
      {
        if (i & 1)
          to += nums[i];
        else
          te += nums[i];
      }
      
      int ten = 0;
      int ton = 0;
      int ans = 0;
      
      for (int i = 0; i < nums.size(); i++)
      {
        if (i & 1)
        {
          int ate = ten + to - ton - nums[i];
          int ato = ton + te - ten;
          if (ate == ato) ans++;
          ton += nums[i];
        }
        else
        {
          int ate = ten + to - ton;
          int ato = ton + te - ten - nums[i];
          if (ate == ato)ans++;
          ten += nums[i];
        }
      }
      return ans;
    }
};