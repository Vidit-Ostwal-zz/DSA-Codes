// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
  
  int  top_down_solution (int W, int wt[],int n)
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
       int temp = 0;
       for (int i =0; i <= memozise[n].size()/2;i++)
       {
           if (memozise[n][i])
           {
               temp = i;
           }
       }
       return temp;
    }
	int minDifference(int arr[], int n)  { 
	    int count = 0;
        for (int i = 0; i < n;i++)
        {
            count += arr[i];
        }
        return abs(count-  2*top_down_solution(count,arr,n));
        
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends