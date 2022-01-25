// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
    int fibo(int n)
    {
        if (n <= 1)
        return n;
        
        int prev2 = 0;
        int prev3 = 1;
        int i = 2;
        while (i <= n)
        {
            int temp = prev3%1000000007;
            prev3 = (prev3%1000000007 + prev2%1000000007)%1000000007;
            prev2 = temp%1000000007;
            i++;
        }
        return prev3%1000000007;
    }
  public:
    int firstElement(int n) 
    {
        return fibo(n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.firstElement(n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends