// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  /*Time Complexity = O(2^N) Recursive Tree
    Sapce Comlplexity = O(N) Height of recursion tree*/
    int recursive_solution (int left_weigth, vector<int> wt, int val[], int index)
    {
        /*Base Condiditon*/
        if (index <0)
        return 0;
        
        /*Case when current weight is higher*/
        if (wt[index] > left_weigth)
        return recursive_solution(left_weigth,wt,val,index-1);
        
        else
        {
            return max(val[index]+recursive_solution(left_weigth - wt[index],wt,val,index),
            recursive_solution(left_weigth,wt,val,index-1));
        }
    }
    
    /*Complexity Analysis: 
    Time Complexity: O(N*W).
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W).
    The use of 2-D array of size ‘N*W’.*/
    int memozization_solution (int left_weigth, vector<int> wt, int val[], int index,vector<vector<int>> &memozise)
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
            return memozise[left_weigth][index] = max(val[index]+memozization_solution(left_weigth - wt[index],wt,val,index,memozise),
            memozization_solution(left_weigth,wt,val,index-1,memozise));
        }
    }
    
    /*Top -Down Appraoch
    Complexity Analysis: 
    Time Complexity: O(N*W).
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W).
    The use of 2-D array of size ‘N*W’.
    Mostly both Memozization solution and top_down_solution will have same complexity.*/
    int top_down_solution (int W, vector<int> wt, int val[], int n)
    {
        vector<vector<int>> memozise(n+1,vector<int>(W+1));
       
       for (int a = 0; a <= n; a++)
       {
           for (int b = 0; b <= W;b++)
           {
               if (a == 0 || b == 0)
               memozise[a][b] = 0;
               
               else if (wt[a-1] <=  b)
               memozise[a][b] = max(val[a-1] + memozise[a][b-wt[a-1]],memozise[a-1][b]);
               
               else
               memozise[a][b] = memozise[a-1][b];
           }
       }
       return memozise[n][W];
    }
    
    int cutRod(int price[], int n) {
        vector<int> weigth;
        for (int i = 1; i <= n;i++)
        weigth.push_back(i);
        
        vector<vector<int>> memozise(n+1,vector<int>(n+1,-1));
        
        return top_down_solution(n,weigth,price,n);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends