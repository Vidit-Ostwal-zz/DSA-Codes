// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    
    /*
    Time Complexity = O(2^N)
    Space Complexity = O(N) Recusion stack Space*/
    int recursive_solution (int *arr, int n, int index)
    {
        if (index >= n)
        return 0;
        
        return max(*(arr+index) + recursive_solution(arr,n,index+2), recursive_solution(arr,n,index+1));
    }
    
    
    
    /*
    Time Complexity = O(N)
    Space Complexity = O(N) Recusion stack Space*/
    int top_down_solution (int *arr, int n,int index,vector<int>&dp)
    {
        if (index >= n)
        return 0;
        
        if (dp[index] != -1)
        return dp[index];
        
        return dp[index] = max(*(arr+index) + top_down_solution(arr,n,index+2,dp), top_down_solution(arr,n,index+1,dp));
    }


    /*Time Complexity = O(N)
    Space Complexity = O(N) Recusion stack Space*/
    int bottom_up_solution (int *arr, int n)
    {
        vector<int> dp(n);
        for (int i = 0; i < n ; i++)
        {
            if (i  < 2)
            dp[i] = (i == 0) ? *arr : max(arr[i],dp[i-1]);
            
            else
            dp[i] = max(*(arr+i) + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }

	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    
	    /*vector<int> dp(n,-1);*/
	    return bottom_up_solution(arr, n);
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