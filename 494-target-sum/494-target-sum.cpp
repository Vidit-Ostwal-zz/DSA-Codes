class Solution {
public:
  
  /*Recursion Solution
  Time Complexity = O(2^N)
  Space Complexity = O(N) Size of Recursion tree*/
  int count_helper(vector<int>nums, int index, int sum, int target)
  {
    if (index == nums.size())
    {
      return (sum == target) ? 1 : 0;
    }
    return count_helper(nums,index+1,sum+nums[index],target) + count_helper(nums,index+1,sum-nums[index],target);
  }
  
    /*Top -Down Appraoch*/
    /*Complexity Analysis: 
    Time Complexity: O(N*W).
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W).
    The use of 2-D array of size ‘N*W’.
    Mostly both Memozization solution and top_down_solution will have same complexity.*/
    int top_down_solution (int W, vector<int>wt,int n)
    {
        vector<vector<int>> memozise(n+1,vector<int>(W+1));
        int mod = pow(10,9) + 7;
       for (int a = 0; a <= n; a++)
       {
           for (int b = 0; b <= W;b++)
           {
               if (b == 0)
               memozise[a][b] = 1;
               
               else if (a == 0)
               memozise[a][b] = 0;
               
               else if (wt[a-1] <=  b)
               {
                   memozise[a][b] = (memozise[a-1][b-wt[a-1]]%mod + memozise[a-1][b]%mod)%mod;
               }
               else
               memozise[a][b] = memozise[a-1][b];
           }
       }
       return memozise[n][W]%mod;
    }
  
    int findTargetSumWays(vector<int>& nums, int target) {
      /*Base Condition*/
      if (nums.size() < 2)
      {
        if (nums.size())
          return (nums[0] == abs(target)) ? 1 : 0;
        else
          return 0;
      }
      int count = 0; 
      
      int total = 0;
      vector<int> modified_vector;
      
      for (int i =0 ; i < nums.size() ; i++)
      {
        if (!nums[i])
          count++;
        else
          modified_vector.push_back(nums[i]);
        
        total += nums[i];
      }
      if ((total + target) % 2)
        return 0;
      return pow(2,count)*top_down_solution((target+total)/2,modified_vector,modified_vector.size());
      
      
    }
};