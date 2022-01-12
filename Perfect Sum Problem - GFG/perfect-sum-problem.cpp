// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    /*Top -Down Appraoch*/
    /*Complexity Analysis: 
    Time Complexity: O(N*W).
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W).
    The use of 2-D array of size ‘N*W’.
    Mostly both Memozization solution and top_down_solution will have same complexity.*/
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
    
    
	public:
	int perfectSum(int arr[], int n, int sum)
	{   int mod = pow(10,9) + 7;
	    int count = 0;
	    vector<int> improvised;
	    for (int i = 0; i < n; i++)
	    {
	        if (arr[i])
	        {
	            improvised.push_back(arr[i]);
	        }
	        else
	        {
	            count++;
	        }
	    }
        return (int(pow(2,count))%mod * top_down_solution(sum,improvised,improvised.size()))%mod;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends