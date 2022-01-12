// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
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
  
    int findTargetSumWays(vector<int>&nums ,int target) {
        int total = 0;
        int count= 0;
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

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends