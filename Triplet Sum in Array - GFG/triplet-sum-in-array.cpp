// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int nums[], int n, int X)
    {
      if (n < 3)
        return false;
      
      sort(nums,nums+n);
      int target = X;
      
      for (int i = 0; i < n -2; i++)
      {
        int first = nums[i];
        int start = i+1;
        int end = n-1;
        
        while (start < end)
        {
          int sum = first + nums[start] + nums[end];
          if ( sum == target)
          {
            start++;
            end--;
            return true;
          }
          else if (sum > target)
          {
            end--;
          }
          else
          {
            start++;
          }
        }
      }
      return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends