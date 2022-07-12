// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    sort(coins, coins + M);
	    
	    vector<vector<long long>> dp (M+1,vector<long long> (V+1,INT_MAX));
	    
	    for (int i = 0; i < dp.size(); i++)
	    {
	        for (int j = 0; j < dp[0].size(); j++)
	        {
	            // i-1 will represent the index in the coins array;
	            // j will represent the value to be calculate
	            
	            // Value is zero
	            if (j == 0)
	            {
	                dp[i][j] = 0;
	            }
	            else if (i == 0)
	            {
	                // No element to make this value
	                dp[i][j] = INT_MAX;
	            }
	            else if (j >= coins[i-1])
	            {
	                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
	            }
	            else
	            {
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    return (dp[M][V] >= INT_MAX) ? -1 : dp[M][V];
	}
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends