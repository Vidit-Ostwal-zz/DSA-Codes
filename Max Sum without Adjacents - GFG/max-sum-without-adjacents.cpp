// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
    int Recursive_Solution (int index, int n, int *arr, vector<int>&dp)
    {
        if (index >= n)
        {
            return 0;
        }
        
        if (dp[index] != -1)
        {
            return dp[index];
        }
        
        return dp[index] = max(arr[index] + Recursive_Solution(index+2,n,arr,dp),Recursive_Solution(index+1,n,arr,dp));
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    
	    
	    vector<int> dp(n,-1);
	   return Recursive_Solution(0,n,arr,dp);
	   
	    
	   // dp[0] = arr[0];
	   // dp[1] = max(arr[0],arr[1]);
	    
	   // for (int i = 2; i < dp.size(); i++)
	   // {
	   //     dp[i] = max(dp[i-1],arr[i] + dp[i-2]);
	   // }
	   // return dp[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends