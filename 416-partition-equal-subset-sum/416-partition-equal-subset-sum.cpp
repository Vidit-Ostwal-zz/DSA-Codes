class Solution {
  bool top_down_solution (int W, vector<int> wt,int n)
    {
        vector<vector<bool >> memozise(n+1,vector<bool>(W+1));
       
       for (int a = 0; a <= n; a++)
       {
           for (int b = 0; b <= W;b++)
           {
               if (b == 0)
               memozise[a][b] = true;
               
               else if (a == 0)
               memozise[a][b] = false;
               
               else if (wt[a-1] <=  b)
               memozise[a][b] = (memozise[a-1][b-wt[a-1]] || memozise[a-1][b]);
               
               else
               memozise[a][b] = memozise[a-1][b];
             
           }
       }
       return memozise[n][W];
    }
    
public:
  
    bool canPartition(vector<int>& arr) {
      int N = arr.size();   
      int count = 0;
        for (int i = 0; i < N;i++)
        {
            count += arr[i];
        }
        if (count % 2 !=0)
        {
            return false;
        }
        else
        return top_down_solution(count/2,arr,N);
    }
};