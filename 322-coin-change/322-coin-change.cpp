class Solution {
public:
  
  int top_down_solution (int W, vector<int> wt, int n)
    {
        vector<vector<int>> memozise(n+1,vector<int>(W+1));
       
       for (int a = 0; a <= n; a++)
       {
           for (int b = 0; b <= W;b++)
           {
               if (a == 0)
               memozise[a][b] = INT_MAX-1;
             
               else if (b == 0)
               memozise[a][b] = 0;
               
             else if (a == 1)
               memozise[a][b] = (b%wt[a-1] == 0) ? b/wt[a-1] : INT_MAX-1;
             
               else if (wt[a-1] <=  b)
               memozise[a][b] = min(1 + memozise[a][b-wt[a-1]],memozise[a-1][b]);
               
               else
               memozise[a][b] = memozise[a-1][b];
           }
       }
       return (memozise[n][W] == INT_MAX -1) ? -1 : memozise[n][W];
    }
  
    int coinChange(vector<int>& coins, int amount) {
        return top_down_solution(amount,coins,coins.size());
    }
};