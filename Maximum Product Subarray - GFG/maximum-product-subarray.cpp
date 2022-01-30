// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
    int answer = INT_MIN;
    void recursive_solution(vector<int> arr, int n,int index,int curr_pro)
    {
        if (index >= arr.size())
        return ;
        
        curr_pro *= arr[index];
        answer = max(answer,curr_pro);
        
        recursive_solution(arr,n,index+1,curr_pro);
        recursive_solution(arr,n,index+1,1);
       return ;
       /*For an index
       1 Take this index and stop
       2 Take this and continue 
       Start a new subarray from next index
       */ 
    }
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long res = INT_MIN;
	    
	    long long l = 1;
	    long long r = 1;
	    
	    for (int i = 0; i < n; i++)
	    {
	        l = l * arr[i];
	        r = r * arr[n-1-i];
	        
	        res = max(res,max(l,r));
	        
	        if (l == 0) l = 1;
	        if (r == 0) r = 1;
	    }
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends