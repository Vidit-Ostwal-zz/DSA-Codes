// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    /*Naive Solution Time Complexity is exponential*/
    int solve(int arr[],int i, int j)
    {
        /*A single matrix is also a valid input 
        The First case when one matrix is multiplied with the rest*/
        /*i==j means that the input is of single matrix nothing can be donw on the single matrix*/
        if (i >= j)
        return 0;
        
        int answer = INT_MAX;
        /*breaking from i to k and k+1 to j*/
        for (int k = i;k < j ;k++)
        {
            answer = min(answer,solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
        }
        return answer;
    }
    
    /*Auxilary Space = O(N^2)
    Time Complexity = O(N^3)*/
    int solvememoized(int arr[],int i, int j,vector<vector<int>> &dp)
    {
        /*A single matrix is also a valid input 
        The First case when one matrix is multiplied with the rest*/
        /*i==j means that the input is of single matrix nothing can be donw on the single matrix*/
        if (i >= j)
        return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        int answer = INT_MAX;
        /*breaking from i to k and k+1 to j*/
        for (int k = i;k < j ;k++)
        {
            answer = min(answer,solvememoized(arr,i,k,dp)+solvememoized(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j]);
        }
        return dp[i][j] = answer;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        /*the matrix is index and index-1, so first thing is to think of write first valid input*/
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return solvememoized(arr,1,N-1,dp);
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