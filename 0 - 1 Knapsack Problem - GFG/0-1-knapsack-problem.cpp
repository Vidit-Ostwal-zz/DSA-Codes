// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    vector<vector<int>> dp;
    public:
    int Recursive_approach(int W, int wt[], int val[], int n, int index, int profit)
    {
        if (W == 0 || index >= n)
        {
            return profit;
        }
        
        if (wt[index] <= W)
        {
            return max(Recursive_approach(W,wt,val,n,index+1,profit),Recursive_approach(W-wt[index],wt,val,n,index+1,profit + val[index]));
        }
        return Recursive_approach(W,wt,val,n,index+1,profit);
    }
    
    
    int Recu_memo(int W, int wt[], int val[], int n, int index)
    {
        if (W == 0 || index >= n)
        {
            return 0;
        }
        
        if (dp[index][W] != -1)
        {
            return dp[index][W];
        }
        
        if (wt[index] <= W)
        {
            return dp[index][W] = max(Recu_memo(W,wt,val,n,index+1),val[index]+ Recu_memo(W-wt[index],wt,val,n,index+1));
        }
        return dp[index][W] = Recu_memo(W,wt,val,n,index+1);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        dp = vector<vector<int>> (n+1,vector<int>(W+1,-1));
       /*return Recursive_approach(W,wt,val,n,0,0);*/
       return Recu_memo(W,wt,val,n,0);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends