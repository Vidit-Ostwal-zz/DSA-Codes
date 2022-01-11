// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{
    bool answer = false;
public:

    /*Time Complexity = O(2^N) Recursive Tree
    Sapce Comlplexity = O(N) Height of recursion tree*/
    void recursive_solution (int left_sum, int wt[], int index)
    {
        /*Base Condiditon*/
        if (answer)
        {
            return;
        }
        if (left_sum == 0)
        {
            answer = true;
            return;
        }
        
        if (index < 0)
        return;
        
        /*Case when current weight is higher*/
        if (wt[index] > left_sum)
        recursive_solution(left_sum,wt,index-1);
        
        else
        {
            recursive_solution(left_sum - wt[index],wt,index-1);
            recursive_solution(left_sum,wt,index-1);
        }
    }
    
    /*Complexity Analysis: 
    Time Complexity: O(N*W).
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W).
    The use of 2-D array of size ‘N*W’.*/
    bool memozization_solution (int left_weigth, int wt[], int index,vector<vector<bool>> &memozise)
    {
        if (left_weigth == 0)
        return true;
        
        /*Base Condiditon*/
        if (index < 0)
        return 0;
        
        /*Solution might be already calculated*/
        if (memozise[left_weigth][index])
        {
            return memozise[left_weigth][index];
        }
        
        /*Case when current weight is higher*/
        if (wt[index] > left_weigth)
        return memozise[left_weigth][index] = memozization_solution(left_weigth,wt,index-1,memozise);
        
        else
        {
            return memozise[left_weigth][index] = memozization_solution(left_weigth - wt[index],wt,index-1,memozise)||
            memozization_solution(left_weigth,wt,index-1,memozise);
        }
    }
    
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
    bool isSubsetSum(int N, int arr[], int sum){
        return top_down_solution(sum,arr,N);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends