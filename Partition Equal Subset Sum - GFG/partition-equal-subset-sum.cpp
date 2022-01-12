// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


class Solution{
public:
/*Top -Down Appraoch*/
    /*Complexity Analysis: 
    Time Complexity: O(N*W).
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W).
    The use of 2-D array of size ‘N*W’.
    Mostly both Memozization solution and top_down_solution will have same complexity.*/
    bool top_down_solution (int W, int wt[],int n)
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
    
    int equalPartition(int N, int arr[])
    {
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends