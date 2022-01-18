// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    int solve (int egg, int flor,vector<vector<int>> &dp)
    {
        if (flor < 2)
        return flor;
        
        if (egg == 1)
        return flor;
        
        if (dp[egg][flor] != -1)
        {
            return dp[egg][flor];
        }
        
        int answer = INT_MAX;
        
        for (int k = 1; k <= flor; k++)
        {
            int at1 = 1 + max (solve(egg-1,k-1,dp),solve(egg,flor-k,dp));
            answer = min(answer,at1);
        }
        return dp[egg][flor] = answer;
    }
    
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        return solve(n,k,dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends