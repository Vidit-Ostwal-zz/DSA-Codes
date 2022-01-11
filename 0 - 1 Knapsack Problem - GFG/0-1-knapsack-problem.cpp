// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    /*Time Complexity = O(2^N) Recursive Tree
    Sapce Comlplexity = O(N) Height of recursion tree*/
    int recursive_solution (int left_weigth, int wt[], int val[], int index)
    {
        /*Base Condiditon*/
        if (index <0)
        return 0;
        
        /*Case when current weight is higher*/
        if (wt[index] > left_weigth)
        return recursive_solution(left_weigth,wt,val,index-1);
        
        else
        {
            return max(val[index]+recursive_solution(left_weigth - wt[index],wt,val,index-1),
            recursive_solution(left_weigth,wt,val,index-1));
        }
    }
    
    /*Complexity Analysis: 
    Time Complexity: O(N*W).
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W).
    The use of 2-D array of size ‘N*W’.*/
    int memozization_solution (int left_weigth, int wt[], int val[], int index,vector<vector<int>> &memozise)
    {
        
        /*Base Condiditon*/
        if (index <0)
        return 0;
        
        /*Solution might be already calculated*/
        if (memozise[left_weigth][index] != -1)
        {
            return memozise[left_weigth][index];
        
        }
        
        /*Case when current weight is higher*/
        if (wt[index] > left_weigth)
        return memozise[left_weigth][index] = memozization_solution(left_weigth,wt,val,index-1,memozise);
        
        else
        {
            return memozise[left_weigth][index] = max(val[index]+memozization_solution(left_weigth - wt[index],wt,val,index-1,memozise),
            memozization_solution(left_weigth,wt,val,index-1,memozise));
        }
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> memozise;
       vector<int> temp(n+1,-1);
       for (int i = 0; i <= W; i++)
       {
           memozise.push_back(temp);
       }
       return memozization_solution(W,wt,val,n-1,memozise);
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