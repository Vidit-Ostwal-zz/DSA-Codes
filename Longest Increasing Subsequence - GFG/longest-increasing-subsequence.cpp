// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int LIS (vector<int> nums, int index, int prev_index, vector<vector<int>>& dp)
  {
    if (index >= nums.size())
      return 0;
    
    if (dp[index][prev_index] != -1)
      return dp[index][prev_index];
    
    if (nums[index] > nums[prev_index])
      return dp[index][prev_index] = max(1+LIS(nums,index+1,index,dp),LIS(nums,index+1,prev_index,dp));
    
    return dp[index][prev_index] = LIS(nums,index+1,prev_index,dp);
  }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       vector<int> nums;
       for (int i = 0; i < n; i++)
       nums.push_back(a[i]);
       
       vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
      int answer = INT_MIN;  
      for (int i = 0; i < nums.size(); i++)
        answer = max(answer,LIS(nums,i+1,i,dp));
      
      return answer+1;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends