// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    /*Recursive Solution*/
    int solve (int i, int j, int arr[])
    {
        if (i >= j)
        return 0;
        int answer = INT_MAX;
        /*Breaking from i to k and k+1 to j*/
        for (int k = i; k < j; k++)
        {
            answer = min(answer,solve(i,k,arr)+solve(k+1,j,arr)+arr[i-1]*arr[k]*arr[j]);
        }
        return answer;
    }
    
    /*Memoization / Bottom Up Solution*/
    int solve_memoization(int i, int j, int arr[],vector<vector<int>> &dp)
    {
        if (i >= j)
        return 0;
        
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int answer = INT_MAX;
        /*Breaking from i to k and k+1 to j*/
        for (int k = i; k < j; k++)
        {
            answer = min(answer,solve_memoization(i,k,arr,dp)+solve_memoization(k+1,j,arr,dp)+arr[i-1]*arr[k]*arr[j]);
        }
        dp[i][j] = answer;
        return answer;
    }
    
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N+1,vector<int> (N+1,-1));
        /*The index represent the right bracket number*/
        return solve_memoization(1,N-1,arr,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends